#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<vector<int>>v(n,vector<int>(3));
    for(int i=0;i<n;i++){
        cin>>v[i][0]>>v[i][1];
        v[i][2] = i;
    }
    sort(v.begin(), v.end(), [](auto &a, auto &b){
    if(a[0] != b[0]) return a[0] < b[0];
    return a[1] > b[1];
});
    vector<int>contain_it(n,0);
    vector<int>contain_other(n,0);
    int max_right = v[0][1];
    int min_right = v[n-1][1];
    for(int i=1;i<n;i++){
        if(max_right>=v[i][1]){
            contain_it[v[i][2]]+=1;
        }
        else{
            max_right = v[i][1];
        }
    }
    for(int i=n-2;i>=0;i--){
        if(min_right<=v[i][1]){
            contain_other[v[i][2]]+=1;
        }
        else{
            min_right = v[i][1];
        }
    }
    for(int i:contain_other){
        cout<<i<<" ";
    }
    cout<<'\n';
    for(int i:contain_it){
        cout<<i<<" ";
    }
    cout<<'\n';
}