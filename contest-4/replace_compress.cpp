#include <iostream>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int sz = s.size();

        bool can_add_2 = false; // True if "000" or "111" exists
        bool can_sub_2 = false; // True if "010" or "101" exists

        for (int i = 1; i <= sz - 2; i++) {
            if (s[i] != s[i - 1] && s[i - 1] == s[i + 1]) {
                can_sub_2 = true;
            } else if (s[i] == s[i - 1] && s[i] == s[i + 1]) {
                can_add_2 = true;
            }
        }

        int ans = 1 + (can_add_2 ? 1 : 0) + (can_sub_2 ? 1 : 0);
        cout << ans << '\n';
    }
    return 0;
    
}

/*the first and last character cant be changed if we assume the final legth of string to be "x" for which 
 we can find only one sting because the alternating characters are fixed (it is not garunteed to always find such sting though)
 so the idea is to calculate number of such lenghts possible */
 //* https://codeforces.com/contest/2276/problem/B