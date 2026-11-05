#include<iostream>
#include<vector>

using namespace std;

int main(){
    int t;cin>>t;
    while (t>0) {
        t--;
        int n;cin>>n;
        bool non_one = false;
        int first_non_one =-1;
        vector<int>v(n);
        long long int sum=0;
        for(int i=0;i<n;i++){
            cin>>v[i];
            if(v[i]!=1 && !non_one && i!=0){
                first_non_one = i;
                non_one = true;
            }
            sum+=v[i];
        }
        if(v[0]!=1) non_one = true;
        if(n==1){
            cout<<v[1]<<'\n';
        }
        else if(n!=1 && !non_one)cout<<-1<<'\n';
        else{
            if(first_non_one!=-1){
                if(first_non_one!=n-1){
                    cout<<sum-1<<'\n';
                }
                else{
                    cout<<sum-(n-1)<<'\n';
                }
            }
            if(first_non_one==-1){
                cout<<v[0]<<'\n';
            }

        }
    }
}