#include<iostream>
using namespace std;
int main(){
    int n;cin>>n;
    int yes=0;
    for(int i=0;i<n;i++){
        int sum = 0;
        for(int j=0;j<3;j++){
            int a;cin>>a;
            sum +=a;
        }
        if(sum >= 2) yes++;
    }
    cout<<yes<<endl;
}
/* x + y = n; x single key , y group key ;
   ax + by = 
*/