#include<iostream>
using namespace std;
const long long int MOD=1e9+7;
const long long inv2 = 500000004;
int main(){
    int n;
    cin>>n;
    if(n%4==1||n%4==2) {
        cout<<0<<endl;
        return 0;
    }
    long long int sum=(n*(n+1))/4;
    long long int dp[sum+1]={};
    dp[0]=1;
    for(long long int i=1;i<n+1;i++){
        for(long long int j=sum;j>=i;j--){
            dp[j]=(dp[j-i]+dp[j])%MOD;
        }
    }
    cout<<(dp[sum] * inv2) % MOD<<endl;
}