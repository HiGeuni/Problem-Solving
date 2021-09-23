#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
vector<ll> nodes;
vector<ll> tree;
vector<ll> lazy;

ll init(int node, int s, int e){
    if(s == e)
        return tree[node] = nodes[s];
    int mid = (s+e)/2;
    return tree[node] = init(2*node, s, mid) + init(2*node + 1, mid+1, e);
}

void lazy_update(int node, int s, int e){
    if(lazy[node] == 0)
        return;
    tree[node] += ((e-s+1) * lazy[node]);
    if(e != s){
        lazy[node*2] += lazy[node];
        lazy[node*2+1] += lazy[node];
    }
    lazy[node] = 0;
}

void update(int node, int s, int e, int l, int r, int diff){
    lazy_update(node, s, e);
    //구간 밖에 있으면
    if(r < s || l > e){
        return;
    }
    if(l <= s && e <= r){
        lazy[node] += diff;
        lazy_update(node, s, e);
        return;
    }
    int mid = (s+e)/2;
    update(node*2, s, mid, l, r, diff);
    update(node*2 + 1, mid +1, e, l, r, diff);
    //루트로 전파해줌
    tree[node] = tree[2*node] + tree[2*node + 1];
}

ll sum_(int node, int s, int e, int l, int r){
    lazy_update(node, s, e);
    if(l > e || r < s)
        return 0;
    if(l <= s && e <= r){
        return tree[node];
    }
    int mid = (s+e)/2;
    return sum_(node*2, s, mid, l, r) + sum_(node*2+1, mid + 1, e, l, r);
}

int main() {
    ll N, M, K, cmd, b, c, d;
    scanf("%lld%lld%lld", &N, &M, &K);
    tree.resize(4*N);
    nodes.resize(N);
    lazy.resize(4*N, 0);
    for(int i=0; i<N; ++i)
        scanf("%lld", &nodes[i]);
    init(1, 0, N-1);
    for(int i=0; i<M+K; ++i){
        scanf("%lld", &cmd);
        //update
        if(cmd == 1){
            scanf("%lld%lld%lld", &b, &c, &d);
            update(1, 0, N-1, b-1, c-1, d);
        }else{
            scanf("%lld%lld", &b, &c);
            printf("%lld\n", sum_(1, 0, N-1, b-1, c-1));
        }
    }
    return 0;
}