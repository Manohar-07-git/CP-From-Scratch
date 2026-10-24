#include<iostream>
using namespace std;

int main(){
    int t;cin>>t;
    while (t>0) {
        t--;
        int n,k;
        cin>>n>>k;
        bool present= false;
        while (n>0) {
            int a;cin>>a;
            if(a==k) present=true;
            n--;
        }

        if(present)cout<<"YES"<<'\n';
        if(!present) cout<<"NO"<<'\n';
    }
}