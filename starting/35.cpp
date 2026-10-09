#include<deque>
#include<iostream>
#include<vector>
using namespace std;
int main(){
    long long int n;cin>>n;
    long long k;cin>>k;
    deque<long long int>d;
    for(long long int i=0;i<n;i++){
        d.push_back(i+1);
    }

    while(d.size()>=1){
        long long int nk = k%d.size();
        for(long long int i=0;i<nk;i++){
            long long out = d.front();
            d.pop_front();
            d.push_back(out);
        }
        cout<<d.front()<<" ";
        d.pop_front();
    }
    

}
