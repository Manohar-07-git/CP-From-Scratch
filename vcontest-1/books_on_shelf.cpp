#include<iostream>
#include<deque>
#include<queue>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int t;
    cin>>t;
    while (t>0) {
        t--;
        int n;cin>>n;
        priority_queue<long long int>pq;
        deque<long long int>dq;
        for(int i=0;i<n;i++){
            long long int a;
            cin>>a;
            pq.push(a);
        }
        bool left=true;
        long long mx = pq.top();
        if(n==1){
            cout<<1<<'\n';
            cout<<pq.top()<<'\n';
            continue;
        }
        // left true add left
        while (!pq.empty()) {
            if(left){
                if(!dq.empty()){
                    if(dq.back()==pq.top()){
                        dq.push_back(pq.top());
                        pq.pop();
                    }
                    else{
                        dq.push_front(pq.top());
                        pq.pop();
                        left=0;
                    }
                }
                else{
                    dq.push_front(pq.top());
                    pq.pop();
                    left=0;
                }
            }
            else if(!left){
                if(dq.front()!=pq.top()){
                    dq.push_front(pq.top());
                    pq.pop();
                }

                else{
                    dq.push_back(pq.top());
                    pq.pop();
                    left=1;
                }
            }
        }
        long long int ans1=1;
        long long int ans2=1;
        
        int cnt=0;
        if(dq[0]==mx)cnt++;
        for(int i=1;i<n;i++){
            if(dq[i]>dq[i-1])ans1++;
            if(dq[n-1-i]>dq[n-i])ans2++;
            if(dq[i]==mx) cnt++;
        }
        cout<<ans1+ans2-(cnt == 1 ? 1 : 0)<<'\n';
        for(int i=0;i<n;i++){

            cout<<dq[i]<<" ";
        }
        cout<<'\n';
    }
}