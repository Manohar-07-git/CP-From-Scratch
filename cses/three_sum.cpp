#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

using namespace std;

pair<int,int> two_pointer(vector<long long int> &v,long long int idx,long long int target){
    long long int n = v.size();
    if(idx>n-3) return {-1,-1};
    int left = idx+1;
    int right = idx+2;
    while(right<n&&left<=right){
        if()
    }
}

int main(){
    int n;cin>>n;
    vector<long long int>v(n);
    map<long long int,int>mp;
    for(int i=0;i<n;i++){
        cin>>v[i];
        mp[v[i]] = i;
    }
    sort(v.begin(),v.end());

    for(int i=0;i<n;i++){

    }

}