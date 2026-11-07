#include<string>
#include<iostream>

using namespace std;

int main(){
    int t;
    cin>>t;
    while (t>0) {
        t--;
        int n,r,b;
        cin>>n>>r>>b;
        string s;
        char red = 'R';
        char blu = 'B';
        
        int mini = r/(b+1);
        int left = r - mini*(b+1);
        while (n>0) {
            for(int i=0;i<mini;i++)s+=red;
            n-=mini;
            if(left>0){
                s+=red;
                s+=blu;
                left--;
                n-=2;
            }
            else if(n>0){
                s+=blu;
                n-=1;
            }
        }

        cout<<s<<'\n';

    }
}