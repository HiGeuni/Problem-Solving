#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef pair<int,int> pii;

int n,m;

vector<pii>v[801];

struct compare{
    bool operator()(pii a, pii b){
        return a.second > b.second;
    }
};

int dijkstra(int start, int end){
    priority_queue<pii, vector<pii>, compare>pq;
    vector<int>dist(801, 2e9);
    dist[start] = 0;
    pq.push({0, start});
    while(!pq.empty()){
        pii cur = pq.top(); pq.pop();
        int curNode = cur.second;
        int curCost = cur.first;
        for(int i=0;i<v[curNode].size(); ++i){
            if(dist[v[curNode][i].first] > curCost + v[curNode][i].second){
                dist[v[curNode][i].first] = curCost + v[curNode][i].second;
                pq.push({dist[v[curNode][i].first], v[curNode][i].first});
            }
        }
    }
    if(dist[end] == 2e9) return -1;
    else return dist[end];
}

int main(){
    int ta, tb, tc,chk1,chk2;
    scanf("%d%d", &n, &m);
    for(int i=0;i<m; ++i){
        scanf("%d%d%d", &ta, &tb, &tc);
        v[ta].push_back({tb, tc});
        v[tb].push_back({ta, tc});
    }
    scanf("%d%d", &chk1, &chk2);
    int t1 = dijkstra(1, chk1);
    int t2 = dijkstra(1, chk2);
    int t3 = dijkstra(chk1, chk2);
    int t4 = dijkstra(chk1, n);
    int t5 = dijkstra(chk2, n);

    int d1 = t1 + t3 + t5;
    int d2 = t2 + t3 + t4;

    if(t3 < 0 || (t1 < 0 || t5 < 0) && (t2 < 0 || t5 < 0)){
        printf("-1");
    }else{
        printf("%d", min(d1, d2));
    }
    return 0;
}