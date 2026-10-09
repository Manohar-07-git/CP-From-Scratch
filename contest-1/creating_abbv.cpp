#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <cctype>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        int n, m;
        cin >> n >> m;

        unordered_set<char> available_chars;

        for (int i = 0; i < n; i++) {
            string w;
            cin >> w;
            available_chars.insert(toupper(w[0]));
        }

        vector<string> a(m);
        vector<bool> used(m, false);

        for (int i = 0; i < m; i++) {
            cin >> a[i];
        }

        int formed_count = 0;
        while (true) {
            bool progress = false;
            for (int i = 0; i < m; i++) {
                if (!used[i]) {
                    unordered_set<char> word_chars(a[i].begin(), a[i].end());
                    
                    bool is_subset = true;
                    for (char c : word_chars) {
                        if (available_chars.find(c) == available_chars.end()) {
                            is_subset = false;
                            break;
                        }
                    }

                    if (is_subset) {
                        used[i] = true;
                        available_chars.insert(a[i][0]);
                        progress = true;
                        formed_count++;
                    }
                }
            }
            if (!progress) break;
        }

        if (formed_count == m) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }

    return 0;
}