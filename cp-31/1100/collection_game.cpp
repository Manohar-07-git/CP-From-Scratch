#include<iostream>
#include<algorithm>
#include<vector>
#include<utility>

using namespace std;

int main(){
    int t;cin>>t;
    while (t>0) {
        t--;
        int n;cin>>n;
        vector<pair<long long int,int>>v(n);
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            long long int a;
            cin>>a;
            v[i] = {a,i};
        }

        
        sort(v.begin(),v.end());
        
        

        vector<long long int>pref_sum(n);

        pref_sum[0] = v[0].first;
        
        for(int i=1;i<n;i++){
            pref_sum[i]=pref_sum[i-1]+v[i].first;
        }

        int start=0;
        
        for(int i=0;i<n;i++){

            if(start<i)start=i;

            while ( start+1<n && v[start+1].first <= pref_sum[start] ) {        
                start++;
            }

            ans[v[i].second] = start;
        }

        for(auto x:ans){
            cout<<x<<" ";
        }
        cout<<'\n';

    }
}