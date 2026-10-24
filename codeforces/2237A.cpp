#include<iostream>
using namespace std;
int main(){
    int num;cin>>num;    
    for(int i=0;i<num;i++){
                int n;cin>>n;
                int arr[n];
                for(int i=0;i<n;i++){
                    cin>>arr[i];
                }
                int sum = 0,least = arr[0];
            for(int i=0;i<n;i++){
                if(arr[i]<least){
                    least = arr[i];
                    sum+=arr[i];
                }
                else if(arr[i]>=least){
                    sum +=least;
                }
            }
            cout<<sum<<endl;
        }
}