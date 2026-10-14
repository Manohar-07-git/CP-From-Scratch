#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, k;
    if (!(cin >> n >> k)) return;

    vector<int> p(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> p[i];
    }

    vector<bool> visited(n + 1, false);
    vector<int> cycle_sizes;

    for (int i = 1; i <= n; ++i) {
        if (!visited[i]) {
            int cur = i;
            int length = 0;
            while (!visited[cur]) {
                visited[cur] = true;
                cur = p[cur];
                length++;
            }
            if (length > 1) {
                cycle_sizes.push_back(length);
            }
        }
    }

    // If the permutation is already sorted, no non-trivial cycles exist
    if (cycle_sizes.empty()) {
        cout << "Alice\n";
        return;
    }

    // If any single cycle cannot be completed within k elements, 
    // Bob can always force a split on that cycle.
    for (int len : cycle_sizes) {
        if (len > k) {
            cout << "Bob\n";
            return;
        }
    }

    // Alice can color up to k elements on turn 1.
    // If the total number of elements in all non-trivial cycles is <= k,
    // Alice colors all of them in a single turn and wins immediately.
    long long total_cycle_elements = 0;
    for (int len : cycle_sizes) {
        total_cycle_elements += len;
    }

    if (total_cycle_elements <= k) {
        cout << "Alice\n";
    } else {
        // If total_cycle_elements > k, Bob can split the cycles across turns
        cout << "Bob\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}