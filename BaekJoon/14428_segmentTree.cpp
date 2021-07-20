#include<iostream>
#include<vector>
using namespace std;

int tree[400004];
int v[100001];

int minIdx(int a, int b){
    if(a == -1) return b;
    if(b == -1) return a;
    return v[a] <= v[b] ? a : b;
}

int init(int s, int e, int node){
    if(s == e) return tree[node] = s;
    int mid = (s+e)/2;
    return tree[node] = minIdx(init(s, mid, 2*node),  init(mid+1, e, 2*node+1));
}

int update(int s, int e, int node,  int idx, int val){
    if(idx < s || e < idx){
        return tree[node];
    }
    if(s == e){
        return tree[node];
    }
    int mid = (s+e)/2;
    return tree[node] = minIdx(update(s, mid, 2*node, idx, val),update(mid+1, e, 2*node+1, idx, val));
}

int getMinIdx(int s, int e, int left, int right, int node){
    if(left > e || right < s){
        return -1;
    }
    if(left <= s && e<=right){
        return tree[node];
    }
    int mid = (s+e)/2;
    return minIdx(getMinIdx(s, mid, left, right, 2*node),getMinIdx(mid+1, e, left, right, 2*node+1));
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N,M;
    cin>>N;
    for(int i=0;i<N; ++i){
        cin>>v[i];
    }
    init(0,N-1, 1);
    cin>>M;
    for(int i=0;i<M; ++i){
        int cmd, a, b;
        cin>>cmd>>a>>b;
        if(cmd == 1){
            v[a-1] = b;
            update(0, N-1, 1, a-1, b);
        }else{
            cout<<getMinIdx(0, N-1, a-1, b-1, 1)+1<<'\n';
        }
    }
    return 0;
}