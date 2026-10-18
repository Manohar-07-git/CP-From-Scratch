#include <algorithm>
#include<iostream>
#include<vector>
#include<string>

using namespace std;

vector<string> solve(int n){
    if(n==1){
        return {"0","1"};
    }
        vector<string>ans;
        vector<string> prev = solve(n-1);
        for(auto c:prev){
            ans.push_back("0"+c);
        }
        reverse(prev.begin(),prev.end());
        for(auto c:prev){
            ans.push_back("1"+c);
        }
        return ans;

    }


int main(){
    int n;cin>>n;
    for(auto c:solve(n)){
        cout<<c<<'\n';
    }
}