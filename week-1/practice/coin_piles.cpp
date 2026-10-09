/*x*2+(t-x) = t+x a+ b >= 2b -a or a+ b >= 2a - b
x + (t-x)*2 = 2t - x;*/
#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    long int t;
    cin>>t;
    vector<string>s;
    for(long int i=0;i<t;i++){
      long long int a,b;
      cin>>a>>b;
      if((a+b)%3 !=0){
        s.push_back("NO");
      }
      else if (2*b>=a && 2*a>=b) {
      s.push_back("YES");
      }
      else s.push_back("NO");
    }
    for(auto c:s){
        cout<<c<<endl;
    }
}
