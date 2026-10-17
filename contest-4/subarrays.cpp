#include <iostream>
#include<vector>

using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t>0) {
        t--;
        int a,k;
        cin>>a>>k;
        vector<vector<int>>mod(k);
        vector<int>v(a+1);
        v[0] = 0;
        mod[0].push_back(0);
        long long int ans=0;
        for(int i=1;i<a+1;i++){
            cin>>v[i];
            v[i] = (v[i]+v[i-1])%k;
            mod[v[i]].push_back(i);
        }
        for(int i=0;i<k;i++){
            //* i represent mod values of prefix sums 
            if(mod[i].empty())continue;
            int m = mod[i].size();
            int r = 0;

    for (int j = 0; j < m; j++) {
        r = max(r, j + 1);

        while (r < m && mod[i][r] <= mod[i][j] + k) {
            r++;
        }

        ans += m - r;
    }
        }
        cout<<ans<<'\n';

    }
}

// Two-pointer on grouped indices: mod[i] contains sorted original indices for remainder i.

// r = max(r, j + 1) guarantees r stays ahead of j (r > j) and avoids resetting to keep linear time.

// Monotonicity: As j increases, the target threshold also increases, so r only ever moves forward.

// Threshold search: The while loop scans until finding the first index where mod[i][r] > mod[i][j] + k.

// Batch counting: All elements from r up to m - 1 are guaranteed valid, adding (m - r) pairs in O(1).

//! https://codeforces.com/contest/2276/problem/C
