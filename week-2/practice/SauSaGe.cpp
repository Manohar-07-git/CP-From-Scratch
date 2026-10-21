#include<iostream>
using namespace std;

long long int pow(int a,int b){
    long long int ans=1;
    while (b>0) {
        ans*=a;
        b--;
    }
    return ans;
}

int main(){
    int t;cin>>t;
    while (t>0) {
        t--;
        int n,k;
        cin>>n>>k;
        long long int ans=0;
        if(k==1){
            cout<<pow(2,n)<<'\n';
            continue;
        }
        cout<<1ll*2*(k-1) + pow(2,n-(k-1))<<'\n';
    }
}