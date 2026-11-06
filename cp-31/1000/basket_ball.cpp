#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long int N,D;
    cin>>N>>D;
    vector<long long int>v(N);
    for(long long int i=0;i<N;i++){
        cin>>v[i];
    }
    // input done do sorting

    sort(v.begin(),v.end());

    long long int end=N-1;
    long long int start=0;
    long long int ans=0;
    while (start<=end) {
        long long int n = D/v[end];
        if(end-start>=n) start+=n;
        else{
            break;
        }
        ans+=1;
        end--;
    }
    cout<<ans<<'\n';

}
//* Binary search method

/*

    
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, D;
    cin >> N >> D;

    vector<long long> v(N);
    for (auto &x : v) cin >> x;

    sort(v.begin(), v.end());

    // Can we form at least k winning teams?
    auto check = [&](long long k) -> bool {
        long long players = 0;

        // Choose the k strongest players as leaders
        for (long long i = N - 1; i >= N - k; i--) {
            long long required = D / v[i] + 1;
            players += required;

            if (players > N)
                return false;
        }

        return true;
    };

    long long low = 0, high = N;
    long long ans = 0;

    while (low <= high) {
        long long mid = low + (high - low) / 2;

        if (check(mid)) {
            ans = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    cout << ans << '\n';
}


*/