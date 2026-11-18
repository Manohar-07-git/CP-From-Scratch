#include <utility>
#include<vector>
#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    while (n>0) {
        n--;
        int t;
    cin>>t;
    if(t<=3){
        cout<<-1<<'\n';
    }
    else{
        vector<int>v(t);
        for(int i=0;i<t;i++){
            v[i]=i+1;
        }
        swap(v[0],v[3]);
        for(int i:v){
            cout<<i<<" ";
        }
        cout<<'\n';
    }
    }
    
}