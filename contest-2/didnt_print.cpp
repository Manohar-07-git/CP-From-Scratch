#include<iostream>
#include<deque>
#include<vector>
#include<string>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;cin>>t;
    while(t>0){
        int n;cin>>n;
        string s;cin>>s;
        vector<int>doc(n,0);
        deque<int>memory;
        vector<int>st(n);
        for(int i=0;i<n;i++){
            st[i] = s[i] - '0';
        }
        for(int i=0;i<n;i++){
            if(st[i]==3)doc[i] = 1;
            else if(st[i]==2){
                if(!memory.empty()){
                    int printed = memory.front();
                    doc[printed] = 1;
                    memory.pop_front();
                }
                else{
                    doc[i] = 1;
                }
            }
            else if(st[i]==1){
                memory.push_front(i);
            }
        }
        int out=n;
        for(int i=0;i<n;i++){
            out -= doc[i];
        }
        cout<<out<<endl;
        for(int i=0;i<n;i++){
            if(doc[i]==0){
                cout<<i+1<<" ";
            }
        }
        cout<<'\n';
        t--;
    }
}