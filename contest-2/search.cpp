#include<iostream>
using namespace std;

int main(){
    int t;cin>>t;
    while(t>0){
        int x,y,r;
        cin>>x>>y>>r;
        cout<<x<<" "<<y+r<<'\n';
        t--;
    }
}
