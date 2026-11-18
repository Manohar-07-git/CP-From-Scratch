#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin>>t;
    while (t>0) {
        t--;
        int n,k;
        cin>>n>>k;
        vector<long long int>v(n);
        vector<long long int>dp(n,0);
        vector<long long int>suff(n+1,0);

        for(int i=0;i<n;i++){
            cin>>v[i];
            v[i]=(v[i]+2)%2;
        }

        // dp[i] = v[i] + dp[i+1] .. dp[i+k-1]
        // suff[i] = dp[i] .... dp[n-1];
        // dp[i] = v[i] + suff(i+1) - suff(min(i+k+1,n))
        // suff[i] = dp[i]+suff[i+1]

        dp[n-1] = v[n-1];
        suff[n]=0;
        suff[n-1] = dp[n-1];

        for(int i=n-2;i>=0;i--){
            dp[i] = (v[i] - suff[min(i+k+1,n)] + suff[i+1] + 2)%2;
            suff[i] = (dp[i]+suff[i+1]+2)%2;
        }

        if(suff[0]%2==1)cout<<"Alice"<<'\n';
        else cout<<"Bob"<<'\n';
        //cout<<suff[0]<<'\n';
    }
}