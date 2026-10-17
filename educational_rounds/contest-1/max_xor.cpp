/*#include <algorithm>
#include<iostream>
#include<bitset>
#include<string>
using namespace std;

int main(){
    int t;cin>>t;
    while (t>0) {
        t--;
        int x, y;
        cin>>x>>y;
        int ans = x+y;
        if(x==0){
            cout<<ans<<" "<<0<<'\n';
            continue;
        }
        string x_bits = bitset<32>(x).to_string();
        string ans_bits = bitset<32>(ans).to_string();
        int i=0;
        while(x_bits[i]=='0'){
            i++;
        }
        // now i had first bit where x has 1 
        string xs;
        bool less=false;
        bool eq=true;
        for(;i<32;i++){
            int anschar = ans_bits[i]-'0';
            int xchar = x_bits[i]-'0';
            // if ans has 1 and if i make corresponding bit of x one will I make x larger than it's value
            // then wrong so x must be less than this
            if(anschar==1){
                if(xchar==1){
                    if(eq){
                        xs+='1';
                    }
                }
                if(xchar==0){
                    if(eq){
                        xs+='0';
                    }
                    else if(less){
                        xs+='1';
                    }
                }   
            }
            else{
                xs+='0';
                if(xchar!=0){
                    less = true;
                    eq = false;
                }
            }
        }
        //reverse(xs.begin(),xs.end());

        int final_x =stoi(xs,nullptr,2);
        cout<<ans<<" "<<x-final_x<<'\n'; 
        
    }

}*/

//! I falied to impliment like this the below is the sloution found in tutorial
#include<bits/stdc++.h>

using namespace std;

void solve()
{
    int x, y;
    cin >> x >> y;
    int s = x + y;
    for(int d = (1 << 30); d >= 1; d >>= 1)
        if((s & d) != 0 && x >= d)
            x -= d;
    cout << s << " " << x << endl;    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for(int i = 0; i < t; i++)
        solve();
}