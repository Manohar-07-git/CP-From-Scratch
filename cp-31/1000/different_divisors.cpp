#include <ios>
#include<iostream>

using namespace std;

bool isprime(long long int n){
    if(n<2) return false;
    if(n==3) return true;
    for(long long int i=2;i*i<=n;i++){
        if(n%i==0) return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;
    while (t>0) {
        t--;
        int d;cin>>d;
        if(d==1){
            cout<<6<<'\n';
            continue;
        }
        long long int start = 1+d;
        while (!isprime(start)) {
            start++;
        }
        // now i had a first prime >= 1+d
        long long int end = start+d;
        while (!isprime(end)) {
            end++;
        }

        cout<<start*end<<'\n';
    }
}