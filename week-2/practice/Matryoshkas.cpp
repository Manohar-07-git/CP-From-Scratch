#include<iostream>
#include<map>
#include<algorithm>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t>0){
        t--;
        int n;cin>>n;
        map<long long int,long long int>mp;
        mp[-1] = -1;
        for(int i=0;i<n;i++){
            long long int a;
            cin>>a;
            mp[a]++;
        }
        auto it = mp.begin();
        it++;
        long long int ans=0;
        while(it!=mp.end()){
            if(it->first - prev(it)->first!=1){
                ans+=it->second;
            }
            else{
                ans += max(1LL*0, it->second - prev(it)->second);
            }
            it++;
        }
        cout<<ans<<'\n';
    }
}

