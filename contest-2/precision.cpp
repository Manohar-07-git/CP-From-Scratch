#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using int64 = long long;
using int128 = __int128_t;

struct Lab {
    int64 a, b, c;
    int64 s;
    int64 overhead; // extra operations needed to unlock
};

void solve() {
    int n;
    int64 k;
    if (!(cin >> n >> k)) return;

    vector<Lab> labs(n);
    int64 low = -4e18, high = 4e18;
    int64 min_s = 4e18;

    for (int i = 0; i < n; ++i) {
        cin >> labs[i].a >> labs[i].b >> labs[i].c;
        labs[i].s = labs[i].a + labs[i].b + labs[i].c;
        min_s = min(min_s, labs[i].s);

        int64 a = labs[i].a, b = labs[i].b, c = labs[i].c;

        if (a == b && b == c) {
            labs[i].overhead = -1; // Permanently unchangeable
            high = min(high, labs[i].s);
        } else if (a > b || a > c || b > c) {
            // Already has a positive gradient (+1 sum per op)
            labs[i].overhead = 0;
        } else {
            // a <= b <= c and not all equal
            int64 d1 = b - a + 1;
            int64 d2 = c - b + 1;
            labs[i].overhead = 2 * min(d1, d2);
        }
    }

    low = min_s;
    high = min(high, min_s + k);

    auto can_reach = [&](int64 target) -> bool {
        int128 total_ops = 0;
        for (const auto& lab : labs) {
            if (lab.s >= target) continue;

            if (lab.overhead == -1) {
                return false;
            }

            int128 diff = (int128)target - lab.s;
            total_ops += diff + lab.overhead;
            if (total_ops > k) return false;
        }
        return total_ops <= k;
    };

    int64 ans = low;
    while (low <= high) {
        int64 mid = low + (high - low) / 2;
        if (can_reach(mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << ans << "\n";
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