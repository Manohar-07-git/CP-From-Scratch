#include<iostream>
#include<string>

int checkrange(int a){
    int ans=0;
    while (a>0) {
        a = a/2;
        ans++;
    }
    return ans;
}

using namespace std;
int main(){
    int t;cin>>t;
    while(t>0){
        t--;
        int n,m;
        cin>>n>>m;
        string x,s;
        cin>>x>>s;
        bool printed = true;
        for(int i=0;i<=checkrange(m);i++){
            if(x.contains(s)){
                printed = false;
                cout<<i<<'\n';
                break;
            }
            else{
                x+=x;
            }
        }
        if(printed)cout<<-1<<'\n';
    } 
    

}