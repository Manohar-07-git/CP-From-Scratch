#include<iostream>
#include<vector>
#include<string>
using namespace std;
const int MOD = 1e9 + 7;
int main(){
    int n;cin>>n;
    vector<string>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    long long int dp[n][n]={};
    dp[0][0]=1;
    if(v[0][0]=='*'){
        cout<<0<<endl;
        return 0;
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(v[i][j]=='*') continue;
            if(i>0){
                dp[i][j]=(dp[i][j]+dp[i-1][j])%MOD;
            }
            if(j>0){
                dp[i][j]=(dp[i][j]+dp[i][j-1])%MOD;
            }
            }
        }
        cout<<dp[n-1][n-1]<<endl;
    }
