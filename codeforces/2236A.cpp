#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int num;cin>>num;
    for(int i=0;i<num;i++){
    int n;
    cin>>n;
    vector<int>v;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        v.push_back(a);
    }
    sort(v.begin(),v.end());
    cout<<v[n-1] - v[0] + 1<<endl;
}
}