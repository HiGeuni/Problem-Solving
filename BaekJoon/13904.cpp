#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;


int main(){
    int n, d, w;
    cin>>n;
    priority_queue<pii>pq;
    vector<int>v(1001, 0);
    //input
    for(int i=0; i<n; ++i){
        cin>>d>>w;
        pq.push({w, d}); // order : w
    }
    while(!pq.empty()){
        pii cur = pq.top(); pq.pop();
        int gain = cur.first;
        int remain = cur.second;
        while(remain > 0 && v[remain] != 0) remain --;
        v[remain] = gain;
    }
    int ans = 0;
    for(int i=1; i<1001; ++i){
        ans += v[i];
    }
    cout<<ans<<endl;
    return 0;
}
