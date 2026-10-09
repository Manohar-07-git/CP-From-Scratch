#include<iostream>
#include<algorithm>
using namespace std;

long long int solve(long long int n){
    long long int mini=9;
    long long int maxi = 0;
    while(n%10!=0||n/10!=0){
        mini = min(mini,n%10);
        maxi = max(maxi,n%10);
        n = n/10;
    }
    return maxi - mini;
}
int main(){
    int t;cin>>t;
    while(t>0){
        long long int ans;
        long long int l,r;
        cin>>l>>r;
        if(l==r){
            ans = l;
        }
        else if(r-l>=100){
            if(l%100 >90)ans = (l/100)*100 + 190;
            else ans = (l/100)*100 + 90;
        }
        else{
            // brute force
            long long int start = l;
            ans = l;
            while(start<=r){
                auto s_ans = solve(ans);
                auto s_start = solve(start);
                ans = (s_ans>s_start) ? ans : start;
                start++;
            }
        }


        cout<<ans<<'\n';
        t--;
    }
}