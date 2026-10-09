#include<iostream>
#include<algorithm>
using namespace std;
int main(){
    int n;cin>>n;
    int steps=0;
    while(n>0){
        int temp=n;
        int digit=0;
        while(temp>0){
        digit=max(digit,temp%10);
        temp=temp/10;
        }
        n=n-digit;
        steps++;
    }
    cout<<steps<<endl;
}