#include<iostream>
#include<vector>
using namespace std;

int main(){

    int t;cin>>t;
    while (t>0) {
        t--;
        int n;cin>>n;
        vector<int>v(n);
        int ones=0;

        for(int i=0;i<n;i++){
            cin>>v[i];
            if(v[i]==1)ones++;
        }
        if(n-ones<2){
            cout<<-1<<'\n';
            continue;
        }

            if(v[0]==0&&v[n-1]==0){
                cout<<0<<'\n';
            }
            else if((v[0]^v[n-1])==1){
                cout<<1<<'\n';
            }
            else{
                cout<<2<<'\n';
            }
        }

    }

