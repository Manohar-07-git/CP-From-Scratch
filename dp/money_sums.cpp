#include<iostream>
#include<numeric>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n;cin>>n;
    vector<int>v;
    long int max_sum=0;
    for(int i=0;i<n;i++){
        int a;cin>>a;
        max_sum+=a;
        v.push_back(a);
    }
    vector<bool>yes(max_sum+1,false);
    yes[0]=true;
    yes[max_sum]=true;
    for(int coin:v){
        for(int s=max_sum;s>=coin;s--){
            yes[s] = yes[s] || yes[s - coin];
        }
    }
    cout<<accumulate(yes.begin()+1,yes.end(),0)<<endl;
    for(int i=1;i<max_sum+1;i++){
        if(yes[i]){
            cout<<i<<" ";
        }
    }
    cout<<endl;

}