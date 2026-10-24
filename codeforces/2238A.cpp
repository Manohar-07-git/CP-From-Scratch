#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n;
        ll c;
        cin >> n >> c;

        vector<ll> a(n), b(n);

        ll suma = 0, sumb = 0;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            suma += a[i];
        }

        for (int i = 0; i < n; i++) {
            cin >> b[i];
            sumb += b[i];
        }

        const ll INF = 4e18;

        ll ans1 = INF, ans2 = INF;

        // Case 1: No reorder
        bool ok = true;
        for (int i = 0; i < n; i++) {
            if (a[i] < b[i]) {
                ok = false;
                break;
            }
        }
        if (ok)
            ans1 = suma - sumb;

        // Case 2: Reorder once
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        ok = true;
        for (int i = 0; i < n; i++) {
            if (a[i] < b[i]) {
                ok = false;
                break;
            }
        }
        if (ok)
            ans2 = (suma - sumb) + c;

        ll ans = min(ans1, ans2);

        if (ans == INF)
            cout << -1 << '\n';
        else
            cout << ans << '\n';
    }

    return 0;
}