#include<cstdio>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
struct Node{
    int w, u, v;
};
struct compare{
    bool operator()(const Node& n1, const Node& n2){
        return n1.w > n2.w;
    }
};

vector<int>parent;

int getParent(int node){
    if(parent[node] == node)
        return parent[node];
    return parent[node] = getParent(parent[node]);
}

void unionParent(int node1, int node2){
    int a = getParent(node1);
    int b = getParent(node2);

    if(a>b){
        parent[a] = b;
    }else{
        parent[b] = a;
    }
}

int main(){
    int N, C;
    scanf("%d%d", &N, &C);
    vector<vector<int>>v(N, vector<int>(2));
    parent.resize(N+1);
    for(int i=0; i<N; ++i){
        parent[i] = i;
    }
    for(int i=0; i<N; ++i)
        scanf("%d%d", &v[i][0], &v[i][1]);
    priority_queue<Node, vector<Node>, compare>pq;
    for(int i=0; i<N; ++i){
        for(int j = i+1; j<N; ++j){
            int tmp = pow((v[i][0] - v[j][0]), 2) + pow((v[i][1] - v[j][1]), 2);
            if(tmp >= C){

                pq.push({tmp, i, j});
            }
        }
    }
    int ans = 0;
    while(!pq.empty()){
        Node cur = pq.top(); pq.pop();
        if(getParent(cur.u) != getParent(cur.v)){
            unionParent(cur.u, cur.v);
            ans += cur.w;
        }
    }
    bool flag = true;
    for(int i=1; i<N; ++i) {
        if (parent[i] != parent[0]) {
            flag = false;
            break;
        }
    }
    if(flag){
        printf("%d", ans);
    }else{
        printf("-1");
    }
}