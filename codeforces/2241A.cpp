#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    while(n>0){
        int x,y;
        cin>>x>>y;
        if(x%y==0){
            cout<<"YES"<<endl;
        }
        else cout<<"NO"<<endl;
        n--;
    }
}