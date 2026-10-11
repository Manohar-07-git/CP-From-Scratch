#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while (t>0) {
        t--;
        int n;cin>>n;
        unordered_set<int>st;
        st.insert(0);
        int pk = 0;
        vector<int>v;
        v.push_back(0);
        bool found = true;
        while(found){
            found = false;
            for(int i=0;i<=n;i++){
                
                if(!st.contains(pk^i)){
                    found = true;
                    pk^=i;
                    v.push_back(i);
                    st.insert(pk^i);
                    break;
                }
            }
            
        }
        cout<<v.size()<<'\n';
        for(int i:v){
            cout<<i<<" ";
        }
        cout<<'\n';

    }
    
}
//* https://codeforces.com/contest/2271/problem/C *