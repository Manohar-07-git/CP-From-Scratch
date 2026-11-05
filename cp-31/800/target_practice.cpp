#include<iostream>
#include<vector>
#include<string>
using namespace std;

int solve(int i,int j){
    if(i==5||i==6){
        if(j==5||j==6) return 5;
    }
    if(i>=4 && i<=7){
        if(j>=4 && j<=7) return 4;
    }
    if(i>=3 && i<=8){
        if(j>=3 && j<=8) return 3;
    }
    if(i>=2 && i<=9){
        if(j>=2 && j<=9) return 2;
    }
    if(i>=1 && i<=10){
        if(j>=1 && j<=10) return 1;
    }
    return 0;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while (t>0) {
        t--;
        int n=10;
        vector<string> v(10);

        for (int i = 0; i < 10; i++) {
            cin >> v[i];
            
        }
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(v[i][j]=='X')ans+=solve(i+1, j+1);
            }
        }
        cout<<ans<<'\n';
    }
}