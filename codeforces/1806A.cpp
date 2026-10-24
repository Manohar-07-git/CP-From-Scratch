#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    vector<long long int> v;

    while (t--) {
        long long int a, b, c, d;
        cin >> a >> b >> c >> d;

        // d must be >= b, and target x (c) must be <= reachable x (a + d - b)
        if (d >= b && (a + d - b) >= c) {
            v.push_back((d - b) + (a + d - b - c));
        } else {
            v.push_back(-1);
        }
    }

    for (auto ans : v) {
        cout << ans << "\n";
    }

    return 0;
}