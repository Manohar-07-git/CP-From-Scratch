#include<iostream>
#include<numeric>
#include<vector>

using namespace std;

int main(){

    int t;cin>>t;

    while (t>0) {
        t--;

        int n;cin>>n;
        vector<long long int>v(n);

        for(int i=0;i<n;i++)cin>>v[i];

        if(n==1){

            cout<<v[0]<<'\n';
            continue;

        }

        if(n==2){
            cout<<gcd(v[0], v[1])<<'\n';
            continue;
        }
        
        long long int greatest_possible = gcd(v[0],v[n-1]);

        cout<<greatest_possible<<'\n';
        

    }

}