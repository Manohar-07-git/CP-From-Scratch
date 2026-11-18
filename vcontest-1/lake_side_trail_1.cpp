#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

bool check(long long int D,long long int k, vector<long long int>& in){
    int n = in.size();
    vector<long long> b(3 * n);

    for (int i = 0; i < 3 * n; i++) {
        b[i] = in[i % n];
    }

    // Left to right
    for (int i = 1; i < 3 * n; i++) {
        b[i] = max(b[i], b[i - 1] - D);
    }

    // Right to left
    for (int i = 3 * n - 2; i >= 0; i--) {
        b[i] = max(b[i], b[i + 1] - D);
    }

    // Minimum soil required
    long long soil = 0;

    for (int i = 0; i < n; i++) {
        soil += b[n + i] - in[i];

        if (soil > k) return false;
    }

    return true;
}

int main(){
    int t;
    cin>>t;
    while (t>0) {
        t--;
        long long int n,k;
        cin>>n>>k;
        vector<long long int>v(n);
        for(long long int i=0;i<n;i++){
            cin>>v[i];
        }

        long long low = 0;
        long long hi = 1e9+1;
        while (low < hi) {
            long long mid = low + (hi - low) / 2;

            if (check(mid, k, v)) {
                hi = mid;
            } else {
                low = mid + 1;
            }
        }
        cout << low << '\n';
    }
}