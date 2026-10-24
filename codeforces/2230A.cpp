#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n, a, b;
        cin >> n >> a >> b;

        long long q = n / 3;
        long long r = n % 3;

        long long cost = q * min(3 * a, b) + min(r * a, b);

        cout << cost << '\n';
    }

    return 0;
}