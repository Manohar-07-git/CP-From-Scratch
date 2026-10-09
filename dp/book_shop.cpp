#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n,x;
    cin>>n>>x;
    int price[n],page[n];
    long long int dp[x+1]={};
    for(int i=0;i<n;i++){
        cin>>price[i];
    }
    for(int i=0;i<n;i++){
        cin>>page[i];
    }
    for(int i=0;i<n;i++){
    for(int money=x;money>=price[i];money--){
        dp[money]=max(dp[money],dp[money-price[i]]+page[i]);
    }
    }
    cout<<dp[x]<<endl;
}