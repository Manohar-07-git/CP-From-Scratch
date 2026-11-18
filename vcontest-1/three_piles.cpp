#include<iostream>

using namespace std;

int main(){
    int t;
    cin>>t;
    while (t>0) {
        t--;
        int a,b,c;
        cin>>a>>b>>c;
        if(a==b && b==c){
            cout<<"NO"<<'\n';
            continue;
        }
        int mini = min(a,min(b,c));
        int maxi = max(a,max(b,c));
        int mid = a+b+c -(maxi+mini);
        if(mini+1==mid && mid+1==maxi){
            cout<<"YES"<<'\n';
        }
        else{
            cout<<"NO"<<'\n';
        }
    }
}