#include<cstdio>
#include<vector>
using namespace std;

vector<int>arr(100001, 0);
vector<int>tree(400004);
int N;

int init(int node, int s, int e){
    if(s == e){
        return tree[node] = s;
    }
    int mid = (s+e)/2;
    int a = init(2*node, s, mid);
    int b = init(2*node+1, mid + 1, e);
    if (arr[a] > arr[b]){
        return tree[node] = b;
    }else if(arr[a] == arr[b]){
        return tree[node] = a>b?b:a;
    }else{
        return tree[node] = a;
    }
}

int update(int node, int s, int e, int idx, int val){
    if(idx < s || e < idx){
        return tree[node];
    }
    if(s == e){
        return tree[node];
    }
    int mid = (s+e)/2;
    int a = update(2 * node, s, mid, idx, val);
    int b = update(2 * node + 1, mid + 1, e, idx, val);
    if(arr[a] == arr[b]){
        return tree[node] = min(a, b);
    }else{
        return tree[node] = arr[a]>arr[b] ? b:a;
    }
}

int main(){
    int q, cmd, idx, val;
    scanf("%d", &N);
    for(int i=1; i<=N; ++i)
        scanf("%d", &arr[i]);
    init(1, 1, N);
    scanf("%d", &q);
    for(int i=0; i<q; ++i){
        scanf("%d", &cmd);
        if(cmd == 1){
            scanf("%d%d", &idx, &val);
            arr[idx] = val;
            update(1, 1, N, idx ,val);
        }else{
            printf("%d\n", tree[1]);
        }
    }
    return 0;
}