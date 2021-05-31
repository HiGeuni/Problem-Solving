#include<iostream>
#include<vector>
#include<utility>
#include<queue>
#include<algorithm>
using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

int main(){
    cin.tie();
    ios_base::sync_with_stdio(false);
    int v, e;
    int from, to, weight;
    cin>>v>>e;
    vector<pii>vec[v+1];
    for(int i=0;i<e; ++i){
        cin>>from>>to>>weight;
        vec[from].push_back({weight, to});
        vec[to].push_back({weight, from});
    }
    int weights[10001] = {0,};
    priority_queue<pii, vector<pii>, greater<pii> >pq;
    pq.push({0,1});
    ll ans = 0;
    while(!pq.empty()){
        pii cur = pq.top();
        pq.pop();

        if(weights[cur.second])
            continue;
        weights[cur.second] = 1;
        ans += cur.first;

        for(int i=0;i<vec[cur.second].size(); ++i){
            //방문하지 않았으면
            if(!weights[vec[cur.second][i].second]){
                pq.push(vec[cur.second][i]);
            }
        }
    }
    cout<<ans;
    return 0;
}
