#include <algorithm>
#include<iostream>
#include<bitset>
#include <istream>
#include<string>

using namespace std;

int main(){
    int t;cin>>t;
    while (t>0) {
        t--;
        int n;cin>>n;
        long long int mini=1e9;
        long long int maxi=0;
        for(int i=0;i<n;i++){
            long long int a;
            cin>>a;
            mini = min(mini,a);
            maxi = max(maxi,a);
        }
        if(mini==maxi){
            cout<<mini<<'\n';
            continue;
        }
        if(n==1){
            cout<<mini<<'\n';
            continue;
        }
        string large = bitset<32>(maxi).to_string();
        string small = bitset<32>(mini).to_string();
        int pos=-1;
        for(int i=0;i<32;i++){
            if(small[i]=='0' && large[i]=='1'){
                pos = i;
                break;
            }
        }
        for(int i=pos+1;i<32;i++){
            large[i] = '1';
        }
        cout<<bitset<32>(large).to_ullong()<<'\n';

    }
}