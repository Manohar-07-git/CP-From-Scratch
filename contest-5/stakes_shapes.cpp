#include<iostream>
#include<string>

using namespace std;

int main(){
    int t;cin>>t;
    while(t>0){
        t--;
        int x,y,z;
        cin>>x>>y>>z;
        int total = x+y+z;
        bool xmax = false;
        bool ymax = false;
        bool zmax = false;
        if(x>=y && x>=z) xmax = true;
        if(y>=z && y>=x) ymax = true;
        if(z>=x && z>=y) zmax = true;
        if(xmax){
            string s(total,'P');
            cout<<s<<'\n';
        }
        else if(ymax){
            string s(total,'R');
            cout<<s<<'\n';
        }
        else if(zmax){
            string s(total,'S');
            cout<<s<<'\n';
        }
    }
}