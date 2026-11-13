#include<iostream>

using namespace std;

int main(){
    int t;
    cin>>t;
    while (t>0) {
        t--;
        long long int a,b;
        cin>>a>>b;
        long long int ans=a;
        long long int xr=0;

        if((a-1)%4==0) xr=a-1;
        else if((a-1)%4==1) xr=1;
        else if((a-1)%4==2) xr=a;
        else xr=0;
        if((xr^a) !=b){
            if(xr==b)cout<<ans<<'\n';
            else cout<<ans+1<<'\n';
        }
        else cout<<ans+2<<'\n';
    }
}