#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>parent;
int find_parent(int n){
    if(parent[n] == n)
        return n;
    return parent[n] = find_parent(parent[n]);
}

void union_parent(int n, int m){
    int a = find_parent(n);
    int b = find_parent(m);
    if(a < b){
        parent[b] = a;
    }else{
        parent[a] = b;
    }
}

int main(){

    cin.tie();
    ios_base::sync_with_stdio(false);
    int N;
    int M;
    cin>>N>>M;
    parent.resize(N+1);
    for(int i=0;i<N+1; ++i){
        parent[i] = i;
    }
    vector<vector<int>>v(N, vector<int>(N));
    for(int i=0;i<N; ++i){
        for(int j=0;j<N; ++j){
            cin>>v[i][j];
            if(v[i][j] == 1){
                union_parent(i+1, j+1);
            }
        }
    }
    bool flag = true;
    vector<int>tmp(M);
    cin>>tmp[0];
    for(int i=1;i<M; ++i){
        cin>>tmp[i];
        if(find_parent(tmp[i-1]) != find_parent(tmp[i])){
            flag = false;
        }
    }
    cout<< (flag ? "YES" :"NO");
    return 0;
}