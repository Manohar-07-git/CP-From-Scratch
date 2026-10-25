#include<algorithm>
#include<utility>
#include<iostream>
#include<vector>

using namespace std;

void makevector(vector<pair<long long int,int>>&A ,vector<long long int>&a ){
    for(int i=0;i<a.size();i++){

            if(a[i]>A[0].first){
                A[2]=A[1];
                A[1]=A[0];
                A[0] = {a[i],i};
            }

            else if (a[i]>A[1].first){     
                A[2] = A[1];
                A[1] = {a[i],i};
            }

            else if(a[i]>A[2].first){
                A[2] = {a[i],i};
            }

        }
}

int main(){
    int t;
    cin>>t;
    while (t>0) {
        t--;
        int n;cin>>n;
        vector<long long int>a(n),b(n),c(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
        }
        for(int i=0;i<n;i++){
            cin>>c[i];
        }
        vector<pair<long long int,int>>A(3,{-1e9,-1});
        vector<pair<long long int,int>>B(3,{-1e9,-1});
        vector<pair<long long int,int>>C(3,{-1e9,-1});
        makevector(A, a);
        makevector(B, b);
        makevector(C, c);

        long long int ans=0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    if((A[i].second==B[j].second)||(B[j].second==C[k].second)||(A[i].second==C[k].second))continue;
                    ans = max(ans,A[i].first+B[j].first+C[k].first);
                }
            }
        }

        cout<<ans<<'\n';

    }
}

/* There is something new I learnt form this problem is that find my intution 
    say the question is about only maximize a+b then simply sort a,b start 2 pointer 

    a[0] a[1] 
    b[0] b[1] these are the first 2 greatest elements now if i choose something other these
    defenitely a + b will not be maximum where my intution gone wrong was that say a[0] > b[0] differ by only 1 and b[1]< a[1]
    differ by 10 then choosing a[0] in the first step is wrong coz a[1] b[0] gvies a +9 overall than the other combination which is true
    but what I made mistake was what if some other than a[1] wich create a differnce of more than 10 with some other b[i] but 
    this is foolish the difference got maximise but the answer didnt

    In this question we have to choose three i,j,k such that a[i]+b[j]+c[k] will be max and i,j,k distnict
    sorting gives first thee max's of all three arrays the i,j,k belong to these indivisual three only coz
    the same previous analogy if i choose something other than these three I can always make sum grater than that
    with these three so just do brute force on 27 combinations done

    but one more intresting this is that instead of sorting I can find the 1,2,3 max in O(N) time but just
    one time array traversal which I hadnt done this before now done first time 
    I could have solve this on my own if I didnt gone through the mistake I was saying before even I can 
    do with this O(N) approach rather than sorting (I reffered tutorial for this).*/