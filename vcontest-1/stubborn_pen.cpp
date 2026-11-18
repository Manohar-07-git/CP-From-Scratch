#include<iostream>
#include<string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while (t>0) {
        t--;
        int n;
        string s;
        cin>>n>>s;
        int ans=0;
        bool red=true;
        for(int i=0;i<n;i++){
            if(s[i]=='R' && red){
                red=false;
            }
            else if(s[i]=='B' && !red){
                red=true;
            }
            else{
                ans++;
            }
        }
        cout<<ans<<'\n';
    }
}