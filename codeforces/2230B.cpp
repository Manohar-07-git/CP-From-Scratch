#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
    string str;
    cin>>str;
    vector<int>v(5,0);
    int count=0;
    for(auto c:str){
        if(c == '4'){
            count++;
            v[4]=1;
        }
        if(c == '1'){
            v[1]=1;
        }
        if(c == '3'){
            v[3]=1;
        }
        if(c=='2'&& (v[3] || v[1]) ){
            count++;
        }
    }
    cout<<count<<endl;
}
}