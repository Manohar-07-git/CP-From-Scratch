#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while (t>0) {
        t--;
        int n,p;
        cin>>n>>p;
        vector<pair<int,int>>v(n,{0,0});
        //
        for(int i=0;i<n;i++){
            int a;cin>>a;
            v[i].second = a;
        }
        //
        for(int i=0;i<n;i++){
            int a;cin>>a;
            v[i].first = a;
        }
        
        sort(v.begin(), v.end(), [](const auto &a, const auto &b) {
            if (a.first != b.first)
                return a.first < b.first;    // Increasing
            return a.second > b.second;      // Decreasing
        });

        // first is decreasing second is increasing

        long long int ans = p;
        //int start=0;
        //int end=n-1;
        int remaning =n-1;
        if(n==1){
            cout<<p<<'\n';
            continue;
        }
        for(int i=0;i<n && remaning>0;i++){
            if(v[i].first>=p) break;
            int take = min(remaning,v[i].second);
            ans+=1ll*take*v[i].first;
            remaning-=take;
        }

        ans+=1LL*remaning*p;
        cout<<ans<<'\n';

    }
}