#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

long long int  solve(vector<long long int>&arr,int idx,long long int curr_sum,long long int total){
    if(idx>=arr.size()){
        return abs(total -2*curr_sum);
    }

    long long int diff_with = solve(arr,idx+1,curr_sum+arr[idx],total);
    long long int diff_without = solve(arr,idx+1, curr_sum, total);
    return min(diff_with,diff_without);

}

int main(){
    int n;cin>>n;
    long long int ans;
    long long int total=0;
    vector<long long int>arr(n);
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
        total+=arr[i];
    }
    
    cout<<solve(arr,0,0,total)<<'\n';
    
}