#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        long long a, b, x;

        cin >> a;
        for (int i = 1; i < n; i++)
            cin >> x;

        cin >> b;
        for (int i = 1; i < m; i++)
            cin >> x;

        long long A = a + n - 1;
        long long B = b + m - 1;

        if (A >= B)
            cout << 1 << '\n';
        else
            cout << 2 << '\n';
    }

    return 0;
}