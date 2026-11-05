#include<iostream>


using namespace std;

int main(){
    int t;cin>>t;
    while (t>0) {
        t--;
        int n;cin>>n;
        int sum=0;
        int prod =1;
        for(int i=0;i<n;i++){
            int a;cin>>a;
            sum+=a;
            prod*=a;
        }

        if(sum>=0 && prod==1){
            cout<<0<<'\n';
        }
        else if(sum>=0 && prod!=1){
            cout<<1<<'\n';
        }
        else if(sum<0){
            sum = -sum;
            int change  = (sum+1)/2;
            prod = (change%2==0) ? prod : -1*prod;
            if(prod!=1)cout<<change+1<<'\n';
            else{
                cout<<change<<'\n';
            }
        }
    }
}