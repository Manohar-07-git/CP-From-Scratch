#include<iostream>
#include<vector>


using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while(t>0){
        t--;
        int n;cin>>n;
        vector<int>v(n);
        vector<int>ans(n,-1);
        bool is = true;
        for(int i=0;i<n;i++){
            cin>>v[i];
            int idx = v[i] +n -i -1;
            if(idx<0 || idx>=n || ans[idx]!=-1){
                is = false;
            }
            else{
                ans[idx] = i+1;
            }
        }
        if(is){
            for(int i:ans){
                cout<<i<<" ";
            }
        }
        else{
            cout<<-1;
        }
        cout<<'\n';
    }
}