#include<iostream>
using namespace std;
int main(){
    int num;cin>>num;
    for(int i=0;i<num;i++){
        long long int n,k;
        cin>>n>>k;
        if(n%2==0) cout<<"YES";
        else if(n%2==1 && k%2==0) cout<<"NO";
        else cout<<"YES";
        cout<<endl;
 
    }
}
//* https://codeforces.com/problemset/problem/1814/A