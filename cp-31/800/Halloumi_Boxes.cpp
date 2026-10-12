#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    // hello
    while(t>0){
        t--;
        int n,k;
        cin>>n>>k;
        vector<long long int>v(n);
        for(int i=0;i<n;i++)cin>>v[i];
        if(k>=2){
            cout<<"YES"<<'\n';
            continue;
        }
        if(k==1){
            if(is_sorted(v.begin(),v.end())){
                cout<<"YES"<<'\n';
            }
            else{
                cout<<"NO"<<'\n';
            }
            continue;
        }

    }
}