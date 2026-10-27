#include<iostream>


using namespace std;

int main(){
    int t;cin>>t;
    while (t>0) {
        t--;
        long long int n;cin>>n;
        
        if(n%2==0){
            cout<<n/2<<" "<<n/2<<'\n';
        }
        
        else{
            long long int d=1;
            for(long long int i=3;i*i<=n;i++){
                if(n%i==0){
                    d = n/i;
                    break;
                }
            }
            cout<<min(d,n-d)<<" "<<max(d,n-d)<<'\n';
        }
    }
}

/*

    if n is even the n/2 ,n/2coz
    one number <=n/2 other >=n/2 
    so n/2,n/2 is the answer
    if n is prime
    1 , n-1 
    becase say 2 number a, b they can have common factor if they had n will also have 
    so it's lcm is x(n-x) which gets minimum at x=1
    but what about odd composite i am unable to judge

    since the case is odd composite same the choose two number a and b
    if a and b are co prime 
    lcm is a*b and which is a(n-a) this is minimum when a = 1(basic quadratic stuff)
    or say if a and b are not co primes a=dx and b = dy
    then x+y = n/d and lcm is d(x)(y) = (n-dy)(y) again this will be minimum at y = 1
    so the lcm is n-d to minimise this choose the greatest divisor of n

*/