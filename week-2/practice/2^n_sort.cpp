#include<iostream>
#include<vector>

using namespace std;

int main(){
    int t;cin>>t;
    while (t>0) {
        t--;
        int n;cin>>n;
        int k;cin>>k;
        vector<long long int>v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        long long int prev_dp=1,curr_dp;
        long long int count=0;
        for(int i=1;i<n;i++){
            if(v[i]-v[i-1]>-v[i]){
                curr_dp = 1+prev_dp;
            }
            else{
                curr_dp=1;
            }
            if(curr_dp>=k+1)count++;
            prev_dp = curr_dp;
        }
        cout<<count<<'\n';
    }
}

// * https://codeforces.com/problemset/problem/1692/G *