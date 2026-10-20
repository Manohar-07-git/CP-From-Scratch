#include<iostream>
#include<queue>


using namespace std;

int main(){
    int t;cin>>t;
    while (t>0) {
        t--;
        int n,k;
        cin>>n>>k;
        priority_queue<int>pq;
        bool printed=true;
        int num_even = 0;
        int mod_three=0;
        for(int i=0;i<n;i++){
            int a;cin>>a;
            if(a%k==2 && k==4)num_even++;
            if(a%k==3 && k==4)mod_three++;
            if(a%k==0)pq.push(k);
            else pq.push(a%k);
        }
        if(k==4 && pq.top()==4){
            cout<<0<<'\n';
        }
        else if(k==4 &&num_even>=2){
            cout<<0<<'\n';
        }
        else if(k==4 && num_even==1){
            cout<<1<<'\n';
        }
        else if(k==4 && num_even==0){
            if(mod_three>=1){
                cout<<1<<'\n';
            }
            else cout<<2<<'\n';
        }
        else{
            cout<<k - pq.top()<<'\n';
        }     
}
}

//* this is not optimal solution why not maintain max remainder element it's better right rather than O(log(n)) insertions right