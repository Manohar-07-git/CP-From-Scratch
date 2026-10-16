#include<iostream>
#include<string>

using namespace std;

int main(){
    int t;cin>>t;
    while(t>0){
        t--;
        string s;
        cin>>s;
        int ones=0;
        int zeros = 0;
        int ans=0;
        for(char c:s){
            if(c-'0'==1){
                ones++;
            }
            else{
                zeros++;
            }            
        }
        if(ones==zeros){
            cout<<0<<'\n';
            continue;
        }
        /*
        for(char c:s){
            if(c=='0' && ones>0){
                ones--;
            }
            else if(c=='0' && ones==0){
                cout<<zeros<<'\n';
                break;
            }
            else if (c=='1' && zeros>0) {
                zeros--;
                
            }
            else {
                cout<<ones<<'\n';
                break;
            }
        }*/
        cout<<ones+zeros - min(ones,zeros)<<'\n';
    }
}

//*  the key idea is that the bits must flip every where so if it is possible do untill then , remove remaining 
//* if ones = zeros answer is 0 else follow the process I can do it better by storing number of ones and zeros till that index i guess 
//* the left over will be maximum of ones and two's there fore why not just return max of (ones,zeros) - min(ones,zeros)   
//* this didnt worked 😅  
//* https://codeforces.com/problemset/problem/1913/B