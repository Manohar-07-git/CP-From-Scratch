#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    int n;cin>>n;
    vector<string>v[n+1];
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    int i=0,j=0;
    string dp[n][n];
    dp[0][0].push_back(v[0][0]);
    while(i<n && j<n){
        if(v[i+1][j]<v[i][j+1]){
            dp[]
        }
    }
}
//to be continued