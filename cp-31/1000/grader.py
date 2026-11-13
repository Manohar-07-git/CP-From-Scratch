#!/usr/bin/env python3
"""Local randomized autograder for Codeforces: split string to maximize f(a)+f(b).

Usage:
    python3 autograder.py solution.cpp
    python3 autograder.py solution.cpp --tests 1000 --seed 42
    python3 autograder.py ./solution --tests 1000  # already compiled
"""
import argparse
import random
import subprocess
import sys
from pathlib import Path


def oracle(s: str) -> int:
    return max(len(set(s[:i])) + len(set(s[i:])) for i in range(1, len(s)))


def build_tests(rng: random.Random, count: int) -> list[str]:
    cases = [
        "aa", "ab", "aaa", "aba", "abc", "aaaaaa", "abcdef",
        "abac", "abab", "aabb", "abba", "abcabc", "zzzzzz",
        "abcdefghijklmnopqrstuvwxyz",
        "abcdefghijklmnopqrstuvwxyz" * 3,
        "a" * 1000,
        "ab" * 500,
        "abcdefghijklmnopqrstuvwxyz" * 100,
    ]
    for _ in range(count):
        n = rng.randint(2, 120)
        mode = rng.randrange(7)
        if mode == 0:
            chars = "a"
        elif mode == 1:
            chars = "ab"
        elif mode == 2:
            chars = "abc"
        elif mode == 3:
            chars = "abcdefghijklmnopqrstuvwxyz"
        elif mode == 4:
            chars = "abcdefghijklmnopqrstuvwxyz"[:rng.randint(1, 26)]
        elif mode == 5:
            half = rng.randint(1, n - 1)
            cases.append(rng.choice("abc") * half + rng.choice("xyz") * (n - half))
            continue
        else:
            base = "".join(rng.choices("abcdef", k=rng.randint(1, 12)))
            cases.append((base * (n // len(base) + 1))[:n])
            continue
        cases.append("".join(rng.choices(chars, k=n)))
    return cases


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument("solution", help="C++ source (.cpp) or compiled executable")
    parser.add_argument("--tests", type=int, default=1000, help="number of random tests (default: 1000)")
    parser.add_argument("--seed", type=int, default=42)
    parser.add_argument("--timeout", type=float, default=10.0, help="seconds for the complete batch")
    args = parser.parse_args()
    if args.tests < 0:
        parser.error("--tests must be nonnegative")

    path = Path(args.solution).expanduser().resolve()
    if not path.is_file():
        sys.exit(f"File not found: {path}")
    if path.suffix == ".cpp":
        exe = Path("/tmp/cf_distinct_split_autograder")
        compile_run = subprocess.run(["g++", "-std=c++17", "-O2", "-Wall", "-Wextra", str(path), "-o", str(exe)], capture_output=True, text=True)
        if compile_run.returncode:
            sys.exit("Compilation failed:\n" + compile_run.stderr)
        command = [str(exe)]
    else:
        command = [str(path)]

    cases = build_tests(random.Random(args.seed), args.tests)
    # CF limits: <=10^4 cases, total n <= 2*10^5. Split into valid batches.
    batches = []
    current, total = [], 0
    for s in cases:
        if len(current) == 10_000 or total + len(s) > 200_000:
            batches.append(current)
            current, total = [], 0
        current.append(s)
        total += len(s)
    if current:
        batches.append(current)

    checked = 0
    for batch_no, batch in enumerate(batches, 1):
        inp = str(len(batch)) + "\n" + "".join(f"{len(s)}\n{s}\n" for s in batch)
        try:
            result = subprocess.run(command, input=inp, capture_output=True, text=True, timeout=args.timeout)
        except subprocess.TimeoutExpired:
            sys.exit(f"TLE: batch {batch_no} exceeded {args.timeout} seconds")
        if result.returncode != 0:
            sys.exit(f"Runtime error in batch {batch_no} (code {result.returncode}):\n{result.stderr}")
        answers = result.stdout.split()
        if len(answers) != len(batch):
            sys.exit(f"Wrong output count in batch {batch_no}: expected {len(batch)}, got {len(answers)}.\nOutput: {result.stdout[:500]}")
        for s, actual in zip(batch, answers):
            expected = oracle(s)
            try:
                parsed = int(actual)
            except ValueError:
                sys.exit(f"Invalid output {actual!r} on input:\n1\n{len(s)}\n{s}")
            if parsed != expected:
                sys.exit(f"WA on test #{checked + 1}\nInput:\n1\n{len(s)}\n{s}\nExpected: {expected}\nGot: {parsed}")
            checked += 1

    print(f"PASS: {checked} test cases across {len(batches)} valid input batch(es). Seed: {args.seed}")


if __name__ == "__main__":
    main()
