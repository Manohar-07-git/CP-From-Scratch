#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while (t>0) {
        t--;
        vector<int>freq(26,0);
        string s;
        int n;
        cin>>n>>s;
        if(n==2){
            cout<<2<<'\n';
            continue;
        }
        int len = s.size();
        vector<int>distinct(len,0);
        distinct[0]=1;
        for(int i=0;i<len;i++){
            if(freq[s[i]-'a']==0 && i!=0){
                distinct[i]=distinct[i-1]+1;
            }
            else if(i!=0){
                distinct[i]=distinct[i-1];
            }
            freq[s[i]-'a']++;
        }
        if(distinct[n-1]==len){
            cout<<len<<'\n';
            continue;
        }
        int i=0;
        int cmp = min(distinct[len-1],len-distinct[len-1]);
        while (i<n-1 && distinct[i]!=cmp) {
            freq[s[i]-'a']--;
            i++;
        }
        freq[s[i]-'a']--;
        int ans=min(distinct[len-1],len-distinct[len-1]);
        for(int j=0;j<26;j++){
            if(freq[j]>0) ans++;
        }
        cout<<ans<<'\n';
    }
}