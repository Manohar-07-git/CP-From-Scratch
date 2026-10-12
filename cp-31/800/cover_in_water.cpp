#include<iostream>
#include<string>

using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while(t>0){
        t--;
        int n;cin>>n;
        string s;
        cin>>s;
        int dot_count=0;
        int three_count=0;
        for(int i=0;i<n;i++){
            if(three_count==1) break;
            if(s[i]=='.')dot_count++;
            if(s[i]=='.'&& i>=1 && i<n-1){
                if(s[i-1]=='.'&&s[i+1]=='.')three_count++;
            }
        }
        if(three_count==1){
            cout<<2<<'\n';
        }
        else{
            cout<<dot_count<<'\n';
        }
    }
}