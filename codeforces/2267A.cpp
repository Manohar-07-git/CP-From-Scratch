#include<iostream>
#include <ratio>
#include<string>

using namespace std;

int main(){
    int t;cin>>t;
    while(t>0){
        int n;cin>>n;
        char c;cin>>c;
        string s;cin>>s;
        int count=0;
        int i,j;
       if(n%2==0){
        i = n/2-1;
        j = i+1;
       }
       else{
        i = n/2-1;
        j = i+2;
       }

        while(i>=0&&j<=n-1){
            
            if(s[i]!=s[j]){
                if(s[i]==c||s[j]==c)count++;
                else count+=2;
                
            }
            i--;j++;
        }

        cout<<count<<'\n';
        t--;
    }
}