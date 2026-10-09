#include<iostream>
#include<vector>

using namespace std;

long long int products(long long time , vector<long long int>&v,long long int x){
    long long int ans = 0;
    for(long long int i:v){
        ans += time/i;
        if(ans>x) return x;
    }
    return ans;
}

int main(){

    long long int n;cin>>n;
    vector<long long int>v(n);
    long long int x;cin>>x;
    for(int i=0;i<n;i++){
        cin>>v[i];
    }

    long long int low = 0;
    long long int high = 1e18;
    long long int mid = low + (high-low)/2 ;
    while(high > low){
        
        mid = low + (high-low)/2;
        if(products(mid, v,x) >=x) high = mid;
        else low = mid+1;

    }
    cout<<low<<'\n';
}