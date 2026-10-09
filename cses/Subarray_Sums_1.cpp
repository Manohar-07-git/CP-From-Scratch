#include <algorithm>
#include<iostream>
#include<vector>

using namespace std;

int main(){
    int n;cin>>n;
    int x;cin>>x;
    vector<long long int>pref_sum(n+1);
    pref_sum.push_back(0);
    for(int i=0;i<n;i++){
        long long int a;cin>>a;
        pref_sum[i+1] = pref_sum[i]+a;
    }

    int count=0;

    /*for(int left=0;left<n+1;left++){
        if(pref_sum[n] - pref_sum[left] <x) break;
        for(int right=left+1;right<n+1;right++){
            if(pref_sum[right] - pref_sum[left] == x){
            count++;

        }
    }
    }*/

    // the above is the brute force idea


    // the 2 pointer approach
    sort(pref_sum.begin(),pref_sum.end());
    int left=0;int right = 1;
    while(left<=right && right<=n+1){ /*missed left<=right while solving wihtout testcases*/
       if(pref_sum[right] - pref_sum[left] == x) {
        count++;
        right++;
        left++;
        
    }
       else if(pref_sum[right] - pref_sum[left] <x){
            right++;
       }
       else{
        left++;
       }  
    }

    

    cout<<count<<'\n';
}