#include<iostream>


using namespace std;

int main(){
    
    int n;cin>>n;
    long long int ans=1;
    long long int prev=-1;
    long long int len=0;
    for(int i=0;i<n;i++){
        long long int curr;
        cin>>curr;
        if(curr>prev){
            len++;
            ans = max(ans,len);
        }
        else{
            len=1;
        }
        prev = curr;
    }

    cout<<ans<<'\n';


}