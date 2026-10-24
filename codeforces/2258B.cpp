#include<vector>
#include<iostream>

using namespace std;

int main(){
    int t;cin>>t;
    while (t>0) {
        t--;
        int n,m;cin>>n>>m;
        vector<int>v(n);
        for(int i=0;i<n;i++)cin>>v[i];

        vector<int>freq(m+2,0);
        vector<int>half(m+2,0);
        for(int i=0;i<n;i++){
            int j=v[i];

            if(v[i]%2==0)half[v[i]/2]++;
            
            freq[1]+=1;
            freq[j+1]--;
            
        }

        for(int i=1;i<m+2;i++){
            freq[i]+=freq[i-1];
        }
        int ans=0;

        for(int i=0;i<m+2;i++){
            ans = max(ans,freq[i]+half[i]);
        }

        cout<<ans<<'\n';
        

    }
}