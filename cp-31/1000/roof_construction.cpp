#include<iostream>
#include<vector>

using namespace std;

int power(int n){
    if(n==1) return 0;
    int i=1;
    while (i<=n){
        i*=2;
    }
    return i/2;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while (t>0) {
        t--;
        int n;cin>>n;
        vector<int>v(n);
        if(n==2){
            cout<<0<<" "<<1<<'\n';
            continue;
        }
        int zero_next = power(n-1);
        for(int i=0;i<n;i++){
            v[i]=i;
        }
        swap(v[0],v[zero_next-1]);

        for(int i:v){
            cout<<i<<" ";
        }
        cout<<'\n';
    }
}

/*
    The thing is that I always thinking what could be the maximum possible answer but the thing is 
    there will be a 2^n I mean MSD suppose it's n=6 you have 4,5,6 whose MSD is 1
    now at least one them has to lie beside to MSD 0 then xor's MSD becomes 1 and you cant stop that
    so now to minimise more furthur make 0 and 2^n side by side this makes the minimum 
    else xor >= 2^n for this edge point 
    
*/