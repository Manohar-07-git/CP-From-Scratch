#include<iostream>
#include<vector>

using namespace std;

int main(){
    int t;cin>>t;
    while (t>0) {
        t--;
        long long int x,y,k;
        cin>>x>>y>>k;
        long long int ans=0;
        long long int diff = y-x;
        if(x>y){
                ans+=y;
                continue;
            }
       long long int n = min(k,max(1LL*0,diff-x+1)); // these many times for loop then dirsct answer
       for(long long int i=0;i<n;i++){
        ans += diff%x;
        x++;
       }

        cout<<ans + (k-n)*diff<<'\n';
    }
}