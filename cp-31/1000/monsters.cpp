#include <algorithm>
#include<iostream>
#include<utility>
#include<vector>

using namespace std;

int main(){
    int t;cin>>t;
    while (t>0) {
        t--;
        int n,k;cin>>n>>k;
        vector<pair<int,int>>v(n);
        
        for(int i=0;i<n;i++){
            int a;cin>>a;
            v[i] = {a%k,i+1};
        }

        sort(v.begin(), v.end(), [](pair<int,int> a, pair<int,int> b) {
                if (a.first != b.first)
                    return a.first < b.first;  // First element ascending
                return a.second > b.second;   // Index descending
            });
        
        int i=0;
        while (i<n && v[i].first==0) {
                i++;
        }
        for(int j=i-1;j>=0;j--){
            cout<<v[j].second<<" ";
        }
        for(int j=n-1;j>i-1;j--){
            cout<<v[j].second<<" ";
        }
        cout<<'\n';


    }
}