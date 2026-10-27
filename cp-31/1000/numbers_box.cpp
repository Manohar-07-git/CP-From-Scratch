#include <cstdlib>
#include <ios>
#include<iostream>
#include<cmath>
#include<vector>

using namespace std;

int main(){
    cin.tie(nullptr);
    ios::sync_with_stdio(false);
    int t;cin>>t;
    while (t>0) {
        t--;
        int n,m;
        cin>>n>>m;
        vector<vector<int>>v(n,vector<int>(m));
        bool iszero=false;
        int mini=101;
        int num_neg=0;
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cin>>v[i][j];
                if(v[i][j]==0)iszero=true;
                mini=min(mini,abs(v[i][j]));
                if(v[i][j]<0)num_neg++;
                ans+=abs(v[i][j]);
            }
        }
        if(iszero) {
            cout<<ans<<'\n';
            
        }
        else if(num_neg%2==0){
            cout<<ans<<'\n';
            
        }
        else{
            cout<<ans-2*abs(mini)<<'\n';
        }

    }
}