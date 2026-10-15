#include <algorithm>
#include<iostream>
#include<functional>
#include<vector>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while (t>0) {
        t--;
        int n;cin>>n;
        vector<int>v(n);
        for(int i=0;i<n;i++){
            cin>>v[i];
        }

        if(is_sorted(v.begin(),v.end())){
            cout<<"YES"<<'\n';
        }
        else if(v[0]!=1){
            cout<<"NO"<<'\n';
        }
        else{
            cout<<"YES"<<'\n';
        }

    }
}

//* 1. say the first digit is not 1 then no
//*   2. say one and last is not max then for some index i ai is max then swap is possible
//*   3. say one and last is max then if second max is not in place then we get swap again 
//*      so on for every ith max therefore if v[0]=1 then aways yes 