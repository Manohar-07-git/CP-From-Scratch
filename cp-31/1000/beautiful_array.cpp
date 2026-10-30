#include<iostream>
#include<vector>

using namespace std;

int main(){
    int t;cin>>t;
    while (t>0) {
        t--;
        long long int n,k,b,s;
        cin>>n>>k>>b>>s;
        vector<long long int>v(n,0);
        if (b*k <= s && s <= b*k + n*(k-1)){
            v[0] = min((b+1)*k-1,s);
            long long int remaining =s-v[0];
            for(int i=1;(i<n)&&remaining>0;i++){
                if(remaining>=k-1){
                    v[i] = k-1;
                    remaining -= k-1;
                }
                else{
                    v[i] = remaining;
                    remaining = 0;
                }
            }
            for(auto i:v){
                cout<<i<<" ";
            }
            cout<<'\n';

        }
        else{
            cout<<-1<<'\n';
        }
    }
}