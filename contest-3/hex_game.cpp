#include<iostream>
#include<map>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t>0){
        t--;
        bool printed = true;
        int n;int k;
        cin>>n>>k;
        
        map<int,int>mp;
        for(int i=0;i<n;i++){
            int a;cin>>a;
            mp[a]++;
        }
        
    for (int i = 0; i <= n; i++) {
    if (mp[i] < 2 * k - 1) {
        cout << "NO\n";
        printed = false;
        break;
    }
    else if (mp[i] == 2 * k - 1) {
        cout << "YES\n";
        printed = false;
        break;
    }
    }
    if(printed)cout<<"NO"<<'\n';

}

}
//* https://codeforces.com/contest/2271/problem/B *