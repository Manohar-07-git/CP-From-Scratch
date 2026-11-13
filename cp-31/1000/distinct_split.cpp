#include<iostream>
#include<vector>
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
        vector<int>forward(26,0);
        vector<int>backward(26,0);
        
        string s;
        int n;
        cin>>n>>s;
        vector<int>pref(n,1);
        vector<int>sufix(n,1);
        if(n==2){
            cout<<2<<'\n';
            continue;
        }
        forward[s[0]-'a']++;
        backward[s[n-1]-'a']++;
        for(int i=1;i<n;i++){
            pref[i]=pref[i-1]+(forward[s[i]-'a']==0);
            forward[s[i]-'a']++;
        }
        for(int i=n-2;i>=0;i--){
            sufix[i]=sufix[i+1] +(backward[s[i]-'a']==0);
            backward[s[i]-'a']++;
        }
        int ans=pref[n-1];
        for(int i=1;i<n;i++){
            ans=max(ans,pref[i-1]+sufix[i]);
        }
        cout<<ans<<'\n';
    }

}


//** !! prefix sum + suffix sum
//* this is an easy problem but I am trying some shitty approach dont know why but this is the first time I am seeing this 
//* But it is quite obvious to do the tags suggest bruteforce and the solution is O(n) 
//* what i was previous doing is get the length of string get the total number of distinct min(distinct[len-1],len-distinct[len-1])
//* go to that number of distinct while reducing then that number + remaining is my answer 
//* wrong in this approach is at for aaba distinct[2]=2 i need to remove the b also from freq i am not doing that 

 /*int i=0;
        int cmp = min(distinct[len-1],len-distinct[len-1]);
        while (i<n-1 && distinct[i]!=cmp) {
            freq[s[i]-'a']--;    
            i++;
        }
        int ans=min(distinct[len-1],len-distinct[len-1]);
        for(int j=0;j<26;j++){
            if(freq[j]>0) ans++;
        }
        cout<<ans<<'\n';*/

/*
Your code outputs 48, but the correct answer is 49.

For this string:
- Length = 111
- Total distinct characters = 26
- cmp = min(26, 111 - 26) = 26

Your while loop searches for the first prefix containing all 26 distinct characters.

Your split:
- Left: s[0...63] → 26 distinct
- Right: s[64...110] → 22 distinct
- Total = 48

Optimal split:
- Left: s[0...54] → 25 distinct
- Right: s[55...110] → 24 distinct
- Total = 49

The logical mistake is assuming that maximizing the number of distinct characters in the left substring always gives the optimal answer.

But 26 + 22 = 48, whereas 25 + 24 = 49.

Therefore, the optimal left substring does not necessarily contain all 26 distinct characters.
*/