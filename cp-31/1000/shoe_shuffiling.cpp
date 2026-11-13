#include <cstddef>
#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while (t>0) {
        t--;
        int n;cin>>n;
        vector<long long int>v(n+1);
        int start=0,end=0;
        bool breaked=false;
        vector<long long int>ans;
        for(int i=0;i<n;i++)cin>>v[i];
        v[n] =-1;
        while(end<=n){
            
            if(v[start]==v[end] && end<n)end++;
            else if(v[start]!=v[end]){
                if(end-start==1){
                    cout<<-1<<'\n';
                    breaked=true;
                    break;
                }
                else{
                    ans.push_back(end);
                    for(int i=0;i<end-start-1;i++){
                        ans.push_back(start+i+1);
                    }
                    start=end;
                    end++;
                }
            }
        }
    
        if(!breaked){
            for(auto i:ans){
            cout<<i<<" ";
            }
        cout<<" "<<'\n';
        }
    }
}