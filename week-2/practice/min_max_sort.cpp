#include<iostream>
#include<map>
using namespace std;

int main(){
    int t;cin>>t;
    while(t>0){
        t--;
        map<int,int>mp;
        int n;cin>>n;
        for(int i=0;i<n;i++){
            int a;cin>>a;
            mp[a] = i; // map value -> index
        }

        int l, r;
        int valid_core = 0;

        if(n%2==0){
            l = n/2;
            r = n/2 + 1;
            if(mp[l] < mp[r]){
                valid_core = 2;
                l--;
                r++;
            }
        }
        else{
            l = (n+1)/2 - 1;
            r = (n+1)/2 + 1;
            valid_core = 1;
        }

        // expand outwards toward 1 and n
        while(l>=1 && r<=n && valid_core > 0){
            if(mp[l] < mp[l+1] && mp[r] > mp[r-1]){
                valid_core += 2;
                l--;
                r++;
            }
            else break;
        }

        int ops = (n - valid_core) / 2;
        cout << ops << "\n";
    }
    return 0;
}

// * https://codeforces.com/problemset/problem/1792/C * 