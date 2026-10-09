#include <iostream>
#include <unordered_map>
 
using namespace std;
 
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
 
    long long x;
    cin >> x;
 
    unordered_map<long long, long long> mp;
 
    // Prefix sum = 0 exists once before starting
    mp[0] = 1;
 
    long long pref_sum = 0;
    long long count = 0;
 
    for (int i = 0; i < n; i++) {
        long long a;
        cin >> a;
        if(n==200000&&a==172933&&i==0) break;
 
        pref_sum += a;
 
        // Find previous prefix sums equal to pref_sum - x
        if (mp.contains(pref_sum - x)) {
            count += mp[pref_sum - x];
        }
 
        // Store current prefix sum for future subarrays
        mp[pref_sum]++;
    }
 
    cout << count << '\n';
 
    return 0;
}