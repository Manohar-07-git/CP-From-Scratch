#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long int n,k;
    cin>>n>>k;
    vector<long long int>v(n+1,0);
    for(long long int i=1;i<n+1;i++){
        cin>>v[i];
    }
    unordered_set<int>st;
    long long int left =1;
    long long int right=1;
    long long int max_left=1;
    long long int max_right=1;
    while(right<=n){
        if(st.empty()){
            st.insert(v[right]);
            right++;
        }
        else if(st.size()<k){
            st.insert(v[right]);
            right++;
        }
        else if(st.size()==k){
            if(!st.contains(v[right])){
                st.clear();
                st.insert(v[right]);
                if(right-left > max_right-max_left){
                    max_left = left;
                    max_right = right-1;
                }
                left=right;
                continue;
            }
            else right++;
        }

        if(right-left > max_right-max_left){
                    max_left = left;
                    max_right = right-1;
                }
    }
    cout<<max_left<<" "<<max_right<<'\n';
}