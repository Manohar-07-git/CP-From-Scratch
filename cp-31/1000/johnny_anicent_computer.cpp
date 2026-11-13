#include<iostream>

using namespace std;

long long int power(long long int n){
    if(n==1) return 0;
    long long int ans=0;
    while (n>1) {
        if(n%2!=0) return -1;
        n=n/2;
        ans+=1;
    }
    return ans;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;cin>>t;
    while (t>0) {
        t--;
        long long int a,b;
        cin>>a>>b;
        if(a<b){
            auto temp = b;
            b=a;
            a=temp;
        }
        if(a%b!=0){
            cout<<-1<<'\n';
            continue;
        }
        long long int n = a/b;
        long long int pow2 = power(n);
        long long int ans=0;
        ans+=pow2/3;
        ans+= (pow2 -3*(pow2/3))/2;
        ans+=pow2 - 3*(pow2/3) - 2*((pow2 -3*(pow2/3))/2);
        cout<<ans<<'\n';
    }
}