#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int t;
    cin>>t;
    while (t>0) {
        t--;
        int n;cin>>n;
        vector<long long int>A;
        vector<long long int>B;
        long long int ans=0;
        for(int i=0;i<n;i++){
            long long int x;cin>>x;
            ans +=abs(x);
            if ((i % 2 == 0 && x >= 0) ||
                (i % 2 == 1 && x < 0)) {
                A.push_back(abs(x));
            }
            else {
                B.push_back(abs(x));
            }
        }

        int odd = (n+1)/2;
        int even  = n/2;
        int negativeA = max(0, (int)A.size() - odd);
        int negativeB = max(0, (int)B.size() - even);

        sort(A.begin(), A.end());
        sort(B.begin(), B.end());
        long long int penalty=0;

        for(int i=0;i<negativeA;i++){
            penalty+=A[i];
        }
        for(int i=0;i<negativeB;i++){
            penalty+=B[i];
        }
        cout<<ans-2*penalty<<'\n';
    }
}