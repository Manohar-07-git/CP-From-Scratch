#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    long long int n;
    cin>>n;
    long long int arr[n];
    for(long long int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<long long int>dp(n);
    for(long long int i=0;i<n;i++){
        for(long long int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                dp[i]++;
            }
            else break;
        }
    }
    cout << *max_element(dp.begin(), dp.end())+1 << endl;
}