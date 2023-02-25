#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

vector<int>parent;

int find(int x){
    if(parent[x] == x) return x;
    return parent[x] = find(parent[x]);
}

void _union(int x, int y){
    x = find(x);
    y = find(y);
    if(x > y){
        parent[x] = y;
    }else{
        parent[y] = x;
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n,m, cmd, ta, tb;
    cin>>n>>m;
    parent.resize(n + 1);
    for(int i=0; i<=n; ++i){
        parent[i] = i;
    }
    for(int i=0; i<m; ++i){
        cin>>cmd>>ta>>tb;
        if(cmd == 1){
            cout<<(find(ta) == find(tb) ? "YES" : " NO")<<'\n';
        }else{
            _union(ta, tb);
        }
    }
    
    return 0;
}
