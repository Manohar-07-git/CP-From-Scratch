#include<iostream>
#include<vector>
using namespace std;
int main(){
        int num;cin>>num;
    for(int i=0;i<num;i++){
                long long int n;cin>>n;
                if(n==10){cout<<-1<<endl;
                    }
                else{
                    if(n%12==10){
                        cout<<22<<" "<<n-22<<endl;
                    }
                    else{
                        cout<<n%12<<" "<<n-n%12<<endl;
                    }
                }
    
}
}