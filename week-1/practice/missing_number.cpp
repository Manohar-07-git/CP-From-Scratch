#include<iostream>
using namespace std;
int main(){
    long int n; cin >>n;
    long int arr[n-1];
    long int sum = 0;
    for(long int i=0;i<n-1;i++){
        cin >>arr[i];
    }
    for(long int i=0;i<n-1;i++){
        sum += arr[i];
    }
    long int sum_n= n*(n+1)/2;
    cout<< sum_n - sum<<endl;
}