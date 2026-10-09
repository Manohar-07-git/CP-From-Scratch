#include<iostream>
#include<vector>
using namespace std;
int main(){
    int n,m;
    cin>>n>>m;
    long long int a[n],b[m];
    vector<long long int>v;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<m;i++){
        cin>>b[i];
    }
    long long int dp[n+1][m+1]={};
    for(int i=n-1;i>=0;i--){
        for(int j=m-1;j>=0;j--){
            if(a[i]==b[j]){
                dp[i][j]=1+dp[i+1][j+1];
            }
            else{
                dp[i][j]=max(dp[i+1][j],dp[i][j+1]);
            }
        }
    }
    int i=0,j=0;
      while(i<n && j<m){

        if(a[i]==b[j]){
            v.push_back(a[i]);
            i++;
            j++;
        }

        else if(dp[i+1][j] >= dp[i][j+1]){
            i++;
        }

        else{
            j++;
        }
    }
    cout<<dp[0][0]<<endl;

    for(long long int x:v){
        cout<<x<<" ";
    }

    cout<<endl;
}