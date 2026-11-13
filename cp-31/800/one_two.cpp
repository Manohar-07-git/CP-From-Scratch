#include<iostream>
#include<map>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t>0){
        t--;
        int count=0;
        int n;cin>>n;
        map<int,int>mp;
        for(int i=0;i<n;i++){
            int a;
            cin>>a;
            if(a==2){
                count++;
                mp[count]=i+1;
            }
        }
        if(count==0){
            cout<<1<<'\n';
        }
        else if(count%2==1)cout<<-1<<'\n';
        else{
            cout<<mp[count/2]<<'\n';
        }
    }
}