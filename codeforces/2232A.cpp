#include<iostream>
#include<map>
using namespace std;
int main(){
    int n;
    cin>>n;
    int mini=1e5,curr=1e5;
    for(int i=0;i<n;i++){
        int mini=1e5,curr=1e5;
        int a;cin>>a;
        int lsum=0,rsum=0;
        map<int,int>mp;
        for(int j=0;j<a;j++){
            int b;cin>>b;
            mp[b] +=1;
        }
        for (auto it = mp.begin(); it != mp.end(); it++) {
            if(it!= mp.begin()){
                lsum += prev(it)->second;
            }
            rsum = a-lsum-it->second;
            curr = max(rsum,lsum);
            mini = min(mini,curr);
        }
        cout<<mini<<endl;
    }
}