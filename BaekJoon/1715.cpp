#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, tmp, ta, tb;
    cin>>n;
    priority_queue<int>pq;
    for(int i=0;i<n; ++i){
        cin>>tmp;
        pq.push(-tmp);
    }
    int ans = 0;
    while(pq.size()!=1){
        ta = -pq.top();
        pq.pop();
        tb = -pq.top();
        pq.pop();
        ans += (ta+tb);
        pq.push(-(ta+tb));
    }
    cout<<ans;
    return 0;
}