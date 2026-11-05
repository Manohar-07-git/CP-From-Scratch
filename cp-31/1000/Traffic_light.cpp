#include<iostream>
#include<string>
#include<vector>


using namespace std;

int main(){
    int t;cin>>t;
    while (t>0) {
        t--;
        int n;
        char c;
        cin>>n>>c;
        string s;
        cin>>s;
        
        if(c=='g')cout<<0<<'\n';
        if(c=='g') continue;

        int i=0;

        int curri=-1;
        vector<int>v;
        vector<int>dist;
        for(int i=0;i<n;i++){
            if(s[i]==c)v.push_back(i);
        }
        int ans=-1;
        int nearest_green=0;
        for(int i:v){
            if(i<nearest_green) continue;
            curri = i;
            nearest_green = i;
            while (nearest_green<n && s[nearest_green]!='g') {
                nearest_green++;
            }
            if(nearest_green<n){
                ans = max(ans,nearest_green-curri);
            }
            else if(nearest_green==n){
                for(int j=0;j<n;j++){
                    if(s[j]=='g'){
                        ans = max(ans,n - curri+j);
                        break;
                    }
                }
            }
        }
        
        cout<<ans<<'\n';

    }
}

//* Learning from the problem is that if i< nearest green then just skip it before i was not doing this so TLE!!
//* and for last non green input in the string explore the idea of taking string + string I mean con cat the string then no need of another for loop inside
