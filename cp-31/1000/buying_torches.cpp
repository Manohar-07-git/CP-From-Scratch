#include <cstddef>
#include<iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while (t>0) {
        t--;
        long long int x,y,k;
        cin>>x>>y>>k;
        long long int n;
        if((k*(y+1)-1)%(x-1)==0) n = (k*(y+1)-1)/(x-1);
        else n = (k*(y+1)-1)/(x-1) +1;

        cout<<n+k<<'\n';
    }
}