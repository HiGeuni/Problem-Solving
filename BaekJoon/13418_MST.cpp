#include<cstdio>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
vector<int>parent;
struct edge{
    int w, u, v;
};
struct comp1{
    bool operator()(const edge& e1, const edge& e2){
        return e1.w > e2.w;
    }
};
struct comp2{
    bool operator()(const edge& e1, const edge& e2){
        return e1.w < e2.w;
    }
};
int getParent(int n){
    if(parent[n] == n){
        return n;
    }
    return parent[n] = getParent(parent[n]);
}

void unionParent(int n1, int n2){
    int a = getParent(n1);
    int b = getParent(n2);
    if(a!=b){
        parent[a] = b;
    }
}

int main(){
    int n, m, tw, tu, tv;
    scanf("%d%d", &n, &m);
    priority_queue<edge, vector<edge>, comp1>minQ;
    priority_queue<edge, vector<edge>, comp2>maxQ;

    for(int i=0; i<m+1; ++i){
        scanf("%d%d%d", &tu, &tv, &tw);
        tw = tw == 0 ? 1 : 0;
        minQ.push({tw, tu, tv});
        maxQ.push({tw, tu, tv});
    }

    int min_ = 0;
    parent.resize(n+1);
    for(int i=0; i<n+1; ++i) parent[i] = i;
    while(!minQ.empty()){
        edge cur = minQ.top(); minQ.pop();
        if(getParent(cur.u) != getParent(cur.v)){
            unionParent(cur.u, cur.v);
            min_ += cur.w;
        }
    }
    int max_ = 0;
    parent.resize(n+1);
    for(int i=0; i<n+1; ++i) parent[i] = i;
    while(!maxQ.empty()){
        edge cur = maxQ.top(); maxQ.pop();
        if(getParent(cur.u) != getParent(cur.v)){
            unionParent(cur.u, cur.v);
            max_ += cur.w;
        }
    }

    printf("%d", max_*max_ - min_*min_);
    return 0;
}