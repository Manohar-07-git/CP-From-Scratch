#include<iostream>
#include<vector>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin>>t;
    while (t>0) {
        t--;
        long long int n,x;
        cin>>n>>x;
        vector<long long int>v(n);
        //
        for(int i=0;i<n;i++){
            cin>>v[i];
        }
        //
        long long int left,right;
        left = v[0]-x;
        right = v[0]+x;
        //
        long long int ans=0;
        for(int i=1;i<n;i++){
            long long int newleft = v[i]-x;
            long long int newright = v[i]+x;
            if(newleft<left && newright<left){
                left=newleft;
                right=newright;
                ans++;
            }
            else if(newleft>right && newright>right){
                left=newleft;
                right=newright;
                ans++;
            }
            else{
                left=max(left,newleft);
                right=min(right,newright);
            }
            
        }

        cout<<ans<<'\n';
        
    }    
}
// can make it better by using O(1) space and one for loop