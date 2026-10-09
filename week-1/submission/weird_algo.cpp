#include<iostream>
using namespace std;
long long int one(long int n){
    if (n==1) {
        return 1;}
 
    if(n%2 == 0) {
        cout<<n/2<<" ";
        return one(n/2);}
 
    if (n%2 == 1) {
        cout<< 3*n +1 <<" ";
        return one( 3*n +1);
    }
}
 
int main(){
long int n; cin>>n;
cout<<n<<" ";
one(n);
}