#include<iostream>
#include<vector>

using namespace std;
    
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;cin>>t;
    while (t>0) {
        t--;
        int n;cin>>n;
        vector<int>v1(n);
        vector<int>v2(n);
        for(int i=0;i<n;i++){
            cin>>v1[i];
        }
        for(int i=0;i<n;i++){
            cin>>v2[i];
        }
        vector<int>A(2*n+1,0);
        vector<int>B(2*n+1,0);
        A[v1[0]] =1;
        B[v2[0]] =1;
        int temp=1;
        for(int i=1;i<n;i++){
            temp=1;
            if(v1[i]!=v1[i-1]){
                temp=1;
                A[v1[i]] = max(temp,A[v1[i]]);
            }
            bool entered = false;
            while (i<n && v1[i]==v1[i-1]) {
                entered = true;
                    temp++;
                    A[v1[i]] = max(temp,A[v1[i]]);
                    i++;
            }
            if(entered)i--;

        }
        for(int i=1;i<n;i++){
            temp=1;
            if(v2[i]!=v2[i-1]){
                temp=1;
                B[v2[i]] = max(temp,B[v2[i]]);
            }
            bool entered = false;
            while (i<n && v2[i]==v2[i-1]) {
                    entered = true;
                    temp++;
                    B[v2[i]] = max(temp,B[v2[i]]);
                    i++;
            }
            if(entered)i--;
        }
        int ans=0;
        for(int i=0;i<2*n+1;i++){
            ans = max(ans,A[i]+B[i]);
        }
        if(n==1){
            if(v1[0]==v2[0])ans=2;
            else ans=1;
        }
        cout<<ans<<'\n';
    }
}

/*

    First I thought of this bucket sort kind of thing but because of size I thought of greedy kind of like 
    If the first elements are same then ans+=2 else choose 1 but that will result in wrong answers for sure 
    then i asked chatgpt for hint and it told the same way i thought of first 
    The key part in this hole was 
    if(n==1){
            if(v1[0]==v2[0])ans=2;
            else ans=1;
        }

        
*/