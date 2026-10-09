#include<iostream>
using namespace std;
 
int main(){
    int n;
    cin>> n;
    int arr[n];
    long long int count=0;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    for(int i=1;i<n;i++){
        if(arr[i-1]>arr[i]){
            
            count += arr[i-1] - arr[i];
            arr[i]=arr[i-1];
        }
    }
    cout<<count<<endl;
}
