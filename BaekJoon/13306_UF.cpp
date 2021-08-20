#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
vector<int>parent(200010);
vector<int>p(200010);

int findParent(int a){
    if(parent[a] == a)
        return a;
    return parent[a] = findParent(parent[a]);
}

void unionParent(int a, int b){
    a = findParent(a);
    b = findParent(b);
    if(a != b){
        parent[b] = a;
    }
}

int main(){
    cin.tie();
    ios_base::sync_with_stdio(0);
    int N,Q;
    cin>>N>>Q;
    for(int i=0; i<N+2; ++i){
        parent[i] = i;
    }
    for(int i=2; i<=N; ++i){
        cin>>p[i];
    }
    int query[400002][3];
    for(int i=0; i<(Q+N-1); ++i){
        cin>>query[i][0];
        if(query[i][0] == 0){
            cin>>query[i][1];
        }else{
            cin>>query[i][1]>>query[i][2];
        }
    }
    vector<string>res;
    for(int i=Q+N-2; i>=0; --i){
        if(query[i][0] == 0){
            unionParent(query[i][1], p[query[i][1]]);
        }else{
            int a = findParent(query[i][1]);
            int b = findParent(query[i][2]);
            if(a == b){
                res.push_back("YES");
            }else{
                res.push_back("NO");
            }
        }
    }
    for(auto i = res.rbegin(); i != res.rend(); ++i){
        cout<< *i<<'\n';
    }
    return 0;
}