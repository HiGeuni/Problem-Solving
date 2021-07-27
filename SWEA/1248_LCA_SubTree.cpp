#include<iostream>
#include<vector>
#include<algorithm>
#include<utility>
using namespace std;
typedef pair<int,int> pii;
#define MAXD 21
vector<vector<int>>parent(MAXD, vector<int>(10001, 0));
vector<vector<int>>graph(10001);
vector<int>depth(10001, 0);

int lca(int a, int b){
    //a의 깊이가 더 깊게 만들기
    if(depth[a] < depth[b]){
        a^=b;
        b^=a;
        a^=b;
    }

    //깊이 맞춰주기
    for(int i = MAXD-1; i>=0; --i){
        if(depth[a] - depth[b] >= 1<<i)
            a = parent[i][a];
    }
    //공통조상 찾기
    for(int i=MAXD-1; i>=0; --i){
        if(parent[i][a] != parent[i][b]){
            a = parent[i][a];
            b = parent[i][b];
        }
    }
    return parent[0][a];
}

int numSubtree(int node){
    int ans = 1;
    for(int i=0;i<graph[node].size();++i){
        ans += numSubtree(graph[node][i]);
    }
    return ans;
}

void dfs(int node,int dept){
    if(dept == MAXD) return;
    depth[node] = dept;
    for(int i=0;i<graph[node].size(); ++i){
        dfs(graph[node][i], dept + 1);
    }
    return;
}

int main(int argc, char** argv)
{
//    ios_base::sync_with_stdio(false);
//    cin.tie(0);
//    cout.tie(0);
    int test_case;
    int T;

    cin>>T;

    for(test_case = 1; test_case <= T; ++test_case)
    {
        for(int i=0;i<MAXD; ++i){
            for(int j=0;j<10001; ++j) {
                parent[i][j] = 0;
            }
        }
        for(int i=0;i<10001; ++i){
            depth[i] = 0;
            graph[i].clear();
        }
        int V, E, Qa, Qb, a1, a2;
        cin>>V>>E>>Qa>>Qb;
        for(int i=0; i<E; ++i){
            cin>>a1>>a2;
//            cout<<a1<<" "<<a2<<endl;
            graph[a1].push_back(a2);
            parent[0][a2] = a1;
        }
        dfs(1, 0);
        for(int i=1; i<MAXD; ++i){
            for(int j=1; j<V+1; ++j){
                parent[i][j] = parent[i-1][parent[i-1][j]];
            }
        }
        vector<int>depth
        int ansLca = lca(Qa, Qb);
        int subTree = numSubtree(ansLca);
        cout<<ansLca<<" "<<subTree<<"\n";

    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}