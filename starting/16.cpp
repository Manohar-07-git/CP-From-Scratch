#include<iostream>
#include<vector>
using namespace std;
#include<cmath>
void solve(int i, long long sum,long long a,long long total) {
    if(i == n) {
        ans = min(ans, abs(total - 2 * sum));
        return;
    }

    solve(i + 1, sum + a[i]); // apple in group 1
    solve(i + 1, sum );        // apple in group 2
}
int main(){
    int n;cin>>n;
    long long int sum=0;
    long long int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        sum+=arr[i];
    }

}