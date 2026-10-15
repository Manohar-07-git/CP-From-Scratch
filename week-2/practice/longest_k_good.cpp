#include<iostream>
#include<vector>

const int MAXA = 1000005;

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
     int n,k;
    cin>>n>>k;
    vector< int>v(n,0);
    for(int i=0;i<n;i++){
        cin>>v[i];
    }
   
    vector< int>freq(MAXA,0);
    int start = 1;
    int end = 1;
    int max_len = 0;
    int l=1,r=1;
    int distinct=0;
    for(end=1;end<=n;end++){

        if(freq[v[end-1]]==0){
            distinct++;
        }
        freq[v[end-1]]++;

         while(distinct>k){
            freq[v[start-1]]--;

            if(freq[v[start-1]]==0){
                    distinct--;
            }

            start++;                
                
            }
        

        if(max_len<end-start+1){
            l = start;
            r = end;
            max_len = end-start+1;
        }
        
    }
    cout<<l<<" "<<r<<'\n';

    
}
//* https://codeforces.com/contest/616/problem/D