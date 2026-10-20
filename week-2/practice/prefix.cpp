#include <cstdlib>
#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int main(){
    int t;
    cin>>t;
    while (t>0) {
        t--;
        int n;cin>>n;

        vector<int>v(n);

        for(int i=0;i<n;i++){
            cin>>v[i];
        }

        vector<long long int>l(n);
        vector<long long int>r(n);
        l[0]=v[0];
        r[0]=v[0];

        for(int i=1;i<n;i++){
            l[i] = min(1ll*v[i],min(v[i]+l[i-1],v[i]+2*l[i-1]));
            r[i] = max(1ll*v[i],max(v[i]+r[i-1],v[i]+2*r[i-1])); 
        }

        long long int ans=-2500;

        for(int i=1;i<n;i++){
            ans = max(ans,1ll*v[i]+ max(abs(l[i-1]),abs(r[i-1])));
        }
        if(ans<v[0])ans=v[0];

        cout<<ans<<'\n';

        

    }
}