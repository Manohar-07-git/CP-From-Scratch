#!/bin/bash
source ~/.bashrc
grep -v "done" ../starting_guide.txt > ../tobedo.txt
cat ../tobedo.txt
