#include<iostream>
using namespace std;

int main(){
    int t;cin>>t;
    while(t>0){
        int n;cin>>n;
        int a1,a2,a3;
        cin>>a1>>a2>>a3;
        int maxi = min(a1,min(a2,a3));
        cout<<n-maxi<<'\n';
        t--;
    }
}