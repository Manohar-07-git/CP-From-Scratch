#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
    int t;cin>>t;
    while(t>0){
        t--;
        int n;cin>>n;
        string str;
        cin>>str;
        vector<int>S;

        for(int i=0;i<n;i++){
            if(str[i]=='1')S.push_back(i+1);
        }
        if(!S.empty() && S.size()>=3){
            cout<<S.back() - S.front()<<'\n';
            continue;
        }
        if(S.size()==1){
            cout<<0<<'\n';
            continue;
        }
        else{
            cout<<1<<'\n';
        }
    }
}