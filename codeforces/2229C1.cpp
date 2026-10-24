#include<iostream>
#include<cmath>
#include<vector>
using namespace std;
int main(){
    int n;cin>>n;
    for(int i=0;i<n;i++){
        long long int a,steps=0;cin>>a;
        long long int arr[a];
        vector<long long int>v;
        for(long long int j =0 ;j<a;j++){
            long long int b;cin>>b;
            arr[j] = b;
        }
        for(long long int j=a-1;j>=0;j--){
            if(pow(-1,steps)*arr[j] > 0){
                steps++;
                v.push_back(j+1);
            }


        }
        cout<<steps<<endl;
        for(auto x :v){
                cout<<x<<" ";
            }
        cout<<endl;
    }
}