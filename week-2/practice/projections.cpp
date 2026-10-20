#include<iostream>
#include<vector>

using namespace std;

int main(){
    int t;cin>>t;
    while (t>0) {
    t--;
    int n;cin>>n;
    vector<long long int >v(n);

    for(int i=0;i<n;i++)cin>>v[i];

    long long int ans=0;

    for(int i=n-1;i>=0;i--){
        ans = 2*v[i] - ans;
    }

    cout<<ans/2<<'\n';



    }
}