#include<iostream>
#include<bitset>
#include<string>

using namespace std;

bool two_pow(int n){
    return (n > 0 && (n & (n - 1)) == 0);
}

int main(){

    int n;cin>>n;
    int ans=1;

    

    while (!two_pow(n)) {
        ans+=(n%2);
        n = n/2;
    }

    cout<<ans<<'\n';



}