#include<iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t>0){
        int a,b;
        cin>>a>>b;
        
        if(a==0&&b==0){
            cout<<0<<'\n';
        }
        else if(b>a+1){
            cout<<-1<<'\n';
        }
        else if(b<=a+1){
            // minimum number of operations is x
            
            if((a+b)%2==0){
                cout<<a<<'\n';
            }
            else{
                cout<<a+1<<'\n';
            }
        }
        t--;
    }
}
//* https://codeforces.com/contest/2271/problem/A *