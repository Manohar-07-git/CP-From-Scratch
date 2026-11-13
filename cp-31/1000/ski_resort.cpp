#include<iostream>


using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while (t>0) {
        t--;
        long long int n,k,q;
        cin>>n>>k>>q;
        long long int start=0,end=0,ans=0;
        for(long long int i=0;i<n;i++){
            long long int a;
            cin>>a;
            if(a<=q){
                end++;
            }
            else if(a>q && end-start>=k){
                long long int sum = end-start;
                ans+=(sum-k+1)*(sum-k+2)/2;
                start=end+1;
                end+=1;
            }
            else if(a>q){
                start=end+1;
                end+=1;
            }
        }
        if(end-start>=k){
            long long int sum = end-start;
            ans+=(sum-k+1)*(sum-k+2)/2;
        }
        cout<<ans<<'\n';
    }
}