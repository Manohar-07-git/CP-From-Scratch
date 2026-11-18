#include<iostream>
#include<string>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;cin>>t;
    while(t>0){
        t--;
        int n;
        string s;
        cin>>n>>s;

        vector<int>v(26,0);
        long long int ans=0;

        int start=0;
        int end=n-1;

        while(start<end){
            int small=min(s[start]-'a',s[end]-'a');
            int large=max(s[start]-'a',s[end]-'a');

            for(int i=small+1;i<=large;i++){
                if(v[i]==0){
                    ans++;
                    v[i]=1;
                }
            }

            start++;
            end--;
        }

        cout<<ans<<'\n';
    }
}