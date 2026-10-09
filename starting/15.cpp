#include <bits/stdc++.h>
using namespace std;

vector<string> ans;
int freq[26];
int n;

void generate(string &current) {
    if (current.size() == n) {
        ans.push_back(current);
        return;
    }

    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            freq[i]--;
            current.push_back('a' + i);

            generate(current);

            current.pop_back();
            freq[i]++;
        }
    }
}

int main() {
    string s;
    cin >> s;

    n = s.size();

    // Count frequency of each character
    for (char c : s) {
        freq[c - 'a']++;
    }

    string current;
    generate(current);

    cout << ans.size() << '\n';

    for (string &s : ans) {
        cout << s << '\n';
    }
}