#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    ll tc,sz,tmp;
    cin>>tc;
    for(int i=0;i<tc; ++i){
        priority_queue<ll>pq;
        cin>>sz;
        for(int j=0;j<sz; ++j){
            cin>>tmp;
            pq.push(-tmp);
        }
        ll ans = 0;
        ll prev = -pq.top();
        pq.pop();
        if(sz == 1){
            cout<<prev<<'\n';
            continue;
        }
        while(1){
            ans += (prev -pq.top());
            pq.push(-(prev-pq.top()));
            pq.pop();
            if(pq.size()>1){
                prev = -pq.top();
                pq.pop();
            }else{
               break;
            }
        }
        cout<<ans<<'\n';
    }
    return 0;
}