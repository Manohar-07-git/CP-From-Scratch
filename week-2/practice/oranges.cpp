#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

long long int solve(long long int n){
    long long int ans=0;
    for(long long l=1,r;l<=n;l=r+1){
        long long q = n/l;
        r = n/q;
        ans+=((l + r) * (r - l + 1) / 2)*q;
    }
    return ans;
}

int main(){

   
        int n;cin>>n;
        for(int i=0;i<n;i++){
            int test;cin>>test;
            vector<long long int>v(test);
            long long int low=1;
            long long int hi=632;
            long long int ans=hi;

            while (low<=hi) {
                auto mid = (low+hi)/2;
                if(solve(mid)>=test){
                    ans = mid;
                    hi = mid-1;
                }
                else{
                    low = mid+1;
                }
            }

            // now I had S in my ans now therefore construct array
            
            int rem = test;         // oranges left to pack
            int bag_id = 1;         // unique ID for each bag
            int idx = 0;            // current index in vector v

            // Iterate bag sizes from S down to 1
            for(int s = ans; s >= 1; s--){
                int max_bags = ans / s; // how many bags of size s we are allowed to make
                
                // While we are allowed to make bags of size s, and we have enough oranges left
                while(max_bags > 0 && rem >= s) {
                    
                    // Put s oranges into the current bag_id
                    for(int k = 0; k < s; k++) {
                        v[idx++] = bag_id;
                    }
                    
                    bag_id++;      // increment ID for the next bag
                    rem -= s;      // we packed s oranges
                    max_bags--;    // one less bag of size s allowed
                }

        }


                
                
            cout<<ans<<'\n';

            for(long long int i:v){
                cout<<i<<" ";
            }
            cout<<'\n';

    }

}