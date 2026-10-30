#include<iostream>
using namespace std;

long long int lcm = 2520;

bool solve(long long int n){
    long long int s=n;
    while (s>0) {
        long long int digit = s%10;
        s = s/10;
        if(digit==0) continue;
        if(!(n%digit==0))return false;
    }
    return true;
}

int main(){
    int t;cin>>t;
    while (t>0) {
        t--;
        long long int n;cin>>n;
        long long int rem = n%lcm;
        if(solve(n)){
            cout<<n<<'\n';
        }
        else if(rem==0){
            cout<<n<<'\n';
        }
        
        else{
            for(int i=1;i<lcm-rem+1;i++){
                if(solve(n+i)){
                    cout<<n+i<<'\n';
                    break;
                }
            }
        }
    }
}

/*

    I saw the tags of this question which says numbertheory because of it Is thinking in direction of some manipulation
    but the thing is I think of the soution in this way the lcm of 1,2,3,4,5,6,7,8,9 is 2520 if this divides the always
    and one more thing because of this constriant I can do brute force as the question tag suggest 

*/