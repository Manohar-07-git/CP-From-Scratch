#include<iostream>
#include<string>
using namespace std;
int main(){
    string s;
    char prev_char;long int count=0,precount=0;
    cin>>s;
    prev_char=s[0];
    for(const auto c: s){
        if(c==prev_char){
            precount++;
            count=max(count,precount);
        }
        else{
            precount=1;
            prev_char=c;
        }
    }
    cout<<count<<endl;
}

// * https://cses.fi/problemset/task/1069