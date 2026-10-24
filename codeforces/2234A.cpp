#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>
#include<functional>
#incl

vector<long long int> fun(vector<long long int> &v){
     vector<long long int>ve;
    sort(v.begin(),v.end(),greater<>());
    for(int i=2;i<v.size();i++){
        if(v[i] != (v[i-2]%v[i-1])){
            ve.push_back(-1);
            return ve;
        }
    }
    ve = {v[0],v[1]};
    return ve;
}

int main(){
    int a;cin>>a;
    for(int j=0;j<a;j++){
    int n;cin>>n;
    vector<long long int>v(n);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
    for(auto x : fun(v)){
        cout<<x<<" ";
    }
    cout<<endl;
}
}