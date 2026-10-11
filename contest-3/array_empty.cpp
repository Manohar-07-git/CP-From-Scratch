#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        long long k;
        cin >> n >> k;

        if (k < 0) {
            cout << -1 << '\n';
            exit(0);
        }

        multiset<int> ms;

        for (int i = 0; i < n; i++) {
            int x;
            cin >> x;
            ms.insert(x);
        }

        long long ans = 0;

        while (!ms.empty()) {
            if (*ms.rbegin() <= k) {
                ans += ms.size();
                break;
            }

            auto it = ms.begin();
            int val = *it;
            ms.erase(it);

            if (val > k) {
                int half = (val + 1) / 2;
                ms.insert(half);
                ms.insert(half);
            }

            k++;
            ans++;
        }

        cout << ans << '\n';
    }

    return 0;
}