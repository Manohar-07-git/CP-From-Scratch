#include<iostream>

using namespace std;

int main(){
    int t;cin>>t;
    while(t>0){
        t--;
        int n,x;
        cin>>n>>x;
        int temp=0;
        int ans=0;
        for(int i=0;i<n;i++){
            int curr;
            cin>>curr;
            ans = max(curr-temp,ans);
            temp = curr;
        }
        ans = max(ans,2*(x-temp));
        cout<<ans<<'\n';
    }
}