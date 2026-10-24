#include<iostream>

using namespace std;

int main(){

int t;cin>>t;
while(t>0){
    long long int a,b,c;
    cin>>a>>b>>c;
    long long int ans;
    // if a>=b take all the c to maximise
    if(a>=b){
        ans = a -b +c;
    }
    else {
        ans = max(a+c-b,b-a);
    }
    cout<<ans<<'\n';
    t--;
}
    
}