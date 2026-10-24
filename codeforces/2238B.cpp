#include<iostream>
using namespace std;
int main(){
    int num;cin>>num;
    while(num>0){
    long long int n;cin>>n;
    long long int b = 1;
    long long int sum = 0;
    while(b<=n){
        sum += (n/b)*(n/b);
        b++;
    }
    cout<<sum<<endl;
    num--;

}
}