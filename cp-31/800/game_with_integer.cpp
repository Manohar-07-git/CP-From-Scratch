#include<iostream>

using namespace std;

int main(){
    int t;cin>>t;
    while(t>0){
        t--;
        int k;cin>>k;
        if(k%3==0){
            cout<<"Second"<<'\n';
        }
        else{
            cout<<"First"<<'\n';
        }
    }
}