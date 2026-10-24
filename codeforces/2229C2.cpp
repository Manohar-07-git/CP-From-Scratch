#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solve() {
    int n;
    cin >> n;
    vector<long long> arr(n); // Using long long prevents integer overflow
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    long long maxi = 0; 
    long long mini = 0;
    int steps = 0;
    vector<int> v;

    for (int i = 0; i < n; i++) {
        // Option 1: Do NOT flip the prefix.
        // We simply accumulate the current element onto our existing ranges.
        long long stay_max = maxi + arr[i];
        long long stay_min = mini + arr[i];

        // Option 2: FLIP the prefix.
        // The history is multiplied by -1. 
        // Therefore, the old mini becomes the basis for the new max, and vice versa.
        long long flip_max = (-mini) - arr[i];
        long long flip_min = (-maxi) - arr[i];

        // Greedily choose the option that gives us the highest maximum value
        if (flip_max > stay_max) {
            maxi = flip_max;
            mini = flip_min;
            steps++;
            v.push_back(i + 1); // 1-based index
        } else {
            maxi = stay_max;
            mini = stay_min;
        }
    }

    cout << steps << endl;
    for (int x : v) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t > 0) {
        solve();
        t--;
    }
    return 0;
}