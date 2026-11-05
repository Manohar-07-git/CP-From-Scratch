#include<iostream>
#include<vector>

using namespace std;

const long long MOD = 998244353;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while (t>0) {
        t--;
        int n,m;
        cin>>n>>m;
        vector<long long int>prev(m+3,0);
        vector<long long int>curr(m+3,0);
        vector<long long int>pref(m+3,0);
        prev[2] = 1; // dp[1][2] = 1
        long long int ans = prev[m+2];
        for(int len=2;len<=n;len++){
            pref[0]=0;
            for(int x=1;x<=m+2;x++){
                pref[x] = (pref[x-1]+prev[x])%MOD;

            }
            for(int x=1;x<=m+2;x++){
                curr[x] = (pref[x]-pref[x/2]+MOD)%MOD;
            }
            ans = (ans + curr[m+2]) % MOD;
            prev.swap(curr);
        }
        
        cout<<ans<<'\n';
    }
}