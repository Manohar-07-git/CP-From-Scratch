#include<iostream>
#include<vector>
#include<string>
#include <utility>
using namespace std;

int main(){
    int t;cin>>t;
    while(t>0){
        int n;cin>>n;
        string s = "YES";
        vector<int>v(n);
        vector<pair<int,int>>dp;

        for(int i=0;i<n;i++){
            cin>>v[i];
            if(v[i]!=i+1){
                dp.push_back({i,v[i]});
            }
        }

        int left = 0;
        int right = dp.size()-1;

        while(left<=right){
            swap(v[dp[left].first],v[dp[right].first]);
            if(v[dp[left].first]!=dp[left].first+1 
            || v[dp[right].first]!= dp[right].first+1){
                s = "NO";
                cout<<s<<'\n';
                break;
            }
            left++;
            right--;
        }
        if(s!="NO") cout<<s<<'\n';

        t--;
        
        
    }
}