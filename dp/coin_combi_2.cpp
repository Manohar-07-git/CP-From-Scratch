#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main() {

    int n, x;
    cin >> n >> x;

    vector<int> coins(n);

    for(int i = 0; i < n; i++) {
        cin >> coins[i];
    }
    sort(coins.begin(),coins.end());
    const int INF = 1e9+7;

    vector<int> dp(x + 1, 0);

    dp[0] = 1;
    for(int coin: coins){
        for(int sum=coin;sum<=x;sum++){
             dp[sum] += dp[sum - coin];

            dp[sum] %= INF;
        }
    }
    cout<<dp[x]<<'\n';
}
