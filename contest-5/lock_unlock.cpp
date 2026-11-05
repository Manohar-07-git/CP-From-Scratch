#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>

using namespace std;

int main(){
    int t;cin>>t;
    while (t>0) {
        t--;
        int n;cin>>n;
        
        vector<long long int>v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        sort(v.begin(),v.end());
        long long int mid = v[n/2];
        long long int ans=0;
        for(int i=0;i<n;i++){
            ans += abs(mid-v[i]);
        }
        cout<<ans<<" "<<v[n-1]-v[0]<<'\n';
    }
}