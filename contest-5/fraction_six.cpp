#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
    int t;cin>>t;
    while (t>0) {
        t--;
        int n,m;
        cin>>n>>m;
        string s1,s2;
        cin>>s1>>s2;
        bool printed=false;
        if(s1.size()!=s2.size()+3){
            printed = true;
            cout<<"NO"<<'\n';
        }
        
        else{
            vector<int>v1(26,0);
            vector<int>v2(26,0);
            for(auto c:s1){
                v1[c-'a']++;
            }
            for(auto c: s2){
                v2[c-'a']++;
            }
            for(int i=0;i<26;i++){
                // s=18,i=8,x=23
                if(i==18 || i==8 || i==23){
                    if(v1[i]!=v2[i]+1){
                        printed = true;
                        cout<<"NO"<<'\n';
                        break;
                    }
                }
                else{
                    if(v1[i]!=v2[i]){
                        printed = true;
                        cout<<"NO"<<'\n';
                        break;
                    }
                }
            }

        }
        if(!printed)cout<<"YES"<<'\n';
    }
}