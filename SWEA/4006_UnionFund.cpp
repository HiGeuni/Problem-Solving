#include<cstdio>
#include<vector>
#include<utility>
#include<cmath>
#include<algorithm>
using namespace std;

struct edge{
    int x, y, cost;
};
bool cmp(edge a, edge b){
    return a.cost < b.cost;
}
vector<int>parent;
vector<edge>edges;

int getParent(int n){
    if(parent[n] == n) return n;
    else parent[n] = getParent(parent[n]);
}

int unionParent(int n, int m){
    int a = getParent(n);
    int b = getParent(m);
    if(a > b){
        parent[a] = b;
    }
    else{
        parent[b] = a;
    }
}

int main(){
    int tc;
    scanf("%d", &tc);
    for(int Tc = 0;Tc < tc; ++Tc){
        int ans =0;
        int N, E, tx, ty, cost;
        scanf("%d%d", &N, &E);
        parent.clear();
        parent.resize(N+1);
        edges.clear();
        for(int i=0; i<E; ++i){
            scanf("%d%d%d", &tx, &ty, &cost);
            edges.push_back({tx, ty, cost});
        }
        sort(edges.begin(), edges.end(), cmp);
//        for debugging
//        for(int i=0; i<E; ++i){
//            printf("%d \n", edges[i].cost);
//        }
        for(int i=1; i<=N; ++i){
            parent[i] = i;
        }
        for(auto x : edges){
            if(getParent(x.x) != getParent(x.y)){
                ans += x.cost;
                unionParent(x.x, x.y);
            }
        }
        printf("#%d %d\n", Tc+1, ans);
    }
    return 0;
}