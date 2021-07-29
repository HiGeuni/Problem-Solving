#include<cstdio>
#include<vector>
#include<utility>
#include<cmath>
#include<algorithm>
using namespace std;

typedef long long ll;
typedef pair<ll,ll> pll;

struct edge{
    double cost;
    int x, y;
};

bool cmp(edge a, edge b){
    return a.cost < b.cost;
}

vector<edge>edges;
vector<pll>v;
vector<int>parent;

int getParent(int n){
    if(parent[n] == n) return n;
    return parent[n] = getParent(parent[n]);
}

int unionParent(int n, int m){
    int a = getParent(n);
    int b = getParent(m);
    if(a > b){
        parent[a] = b;
    }else{
        parent[b] = a;
    }
}

int main(){
    int tc;
    scanf("%d",  &tc);
    for(int testCase = 1; testCase <= tc; ++testCase){
        int N;
        double e;
        double ans = 0;
        scanf("%d", &N);
        v.clear();
        v.resize(N);
        parent.clear();
        parent.resize(N);
        edges.clear();
        for(int i=0;i<N; ++i)
            scanf("%lld", &v[i].first);
        for(int i=0;i<N; ++i)
            scanf("%lld", &v[i].second);
        scanf("%lf", &e);
        for(int i=0;i<N; ++i){
            for(int j=i+1; j<N; ++j){
                edges.push_back({(pow(v[i].first - v[j].first, 2) + pow(v[i].second - v[j].second,2)) * e, i, j});
            }
        }
        sort(edges.begin(), edges.end(), cmp);
        for(int i=0; i<N; ++i){
            parent[i] = i;
        }
        //for debuging
//        for(auto X : edges) {
//            printf("cost : %d, x : %d, y : %d\n", X.cost, X.x, X.y);
//        }
        for(auto cur : edges){
            if(getParent(cur.x) != getParent(cur.y)){
                ans += cur.cost;
                unionParent(cur.x, cur.y);
            }
        }
        printf("#%d %.0lf\n", testCase, ans);
    }
}