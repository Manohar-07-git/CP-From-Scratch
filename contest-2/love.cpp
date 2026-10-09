#include<iostream>
#include<vector>
#include<map>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t>0){
        int n;cin>>n;
        vector<int>a(n);
        map<int,int>mp;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n-4;i++){
            mp[i] = a[i] +a[i+2] - a[i+4];;
        }
        map<int,int>freq;
       
        
        long long int count=0;
        for(int y=0;y<n-4;y++){
            count+=freq[mp[y]];
            if(y>=2 && mp[y-2]==mp[y])count--;
            if(y>=4 && mp[y-4]==mp[y])count--;
            freq[mp[y]]++;
        }
        cout<<count<<'\n';
        t--;

    }

}