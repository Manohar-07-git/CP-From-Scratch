#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while (t>0) {
        t--;
        int a,b;
        cin>>a>>b;
        if(a<=b){
            cout<<-1<<'\n';
            continue;
        }
        else if(a>=2*b){
            cout<<b<<'\n';
            continue;
        }
        else{
            cout<<a-b<<'\n';
        }
    }   
}