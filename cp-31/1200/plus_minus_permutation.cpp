#include<iostream>
#include<numeric>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin>>t;
    while (t>0) {
        t--;
        long long int n,x,y;
        cin>>n>>x>>y;
        long long int lcm_xy = lcm(x, y);
        long long int num_x = n/x - n/lcm_xy;
        long long int num_y = n/y - n/lcm_xy;
        // num_x + num_y + n/lcm_xy <= n
        long long int ans=0;
        /*for(long long int i=0;i<num_x;i++){
            ans+=(n-i);
        }
        for(long long int i=0;i<num_y;i++){
            ans-=(i+1);
        }*/
        ans+= n*(n+1)/2 - num_y*(num_y+1)/2 - (n-num_x)*(n-num_x+1)/2;
        cout<<ans<<'\n';
    }
}