#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#include<queue>
#include<cstring>
using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
#define MAX 100005
#define MAXD 20
//vector가 너무 느림
int parent[MAXD][MAX];
int depth[MAX];
bool visited[MAX];
vector<vector<int>>graph(MAX);

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
    if(a == b) return a;
    //공통조상 찾기
    for(int i=MAXD-1; i>=0; --i){
        if(parent[i][a] != parent[i][b]){
            a = parent[i][a];
            b = parent[i][b];
        }
    }
    return parent[0][a];
}


int main(int argc, char** argv)
{
    int test_case;
    int T;

    scanf("%d", &T);

    for(test_case = 1; test_case <= T; ++test_case)
    {

        int N, tmp;
        scanf("%d", &N);
        memset(parent, 0, sizeof(parent));
        memset(depth, 0, sizeof(depth));
        memset(visited, 0, sizeof(visited));
        graph.clear();
        graph.resize(N+5);

        for(int i=1; i<N; ++i){
            scanf("%d", &tmp);
            graph[tmp].push_back(i+1);
            parent[0][i+1] = tmp;
        }

        for(int i=1;i<=N; ++i)
            sort(graph[i].begin(), graph[i].end());

        //깊이 찾기
        deque<pair<int,int>>dpi;
        dpi.push_back({1,0});
        visited[1] = true;
        while(!dpi.empty()){
            int cur = dpi.front().first;
            int dpt = dpi.front().second;
            dpi.pop_front();
            depth[cur] = dpt;
            for(int next : graph[cur]){
                if(!visited[next]){
                    visited[next] = true;
                    dpi.push_back({next, dpt+1});
                }
            }
        }

        for(int i=1; i<MAXD; ++i)
            for(int j=1; j<N+1; ++j)
                parent[i][j] = parent[i-1][parent[i-1][j]];

//        for(int i=1; i<MAXD; ++i){
//            for(int j=1; j<N+1; ++j){
//                printf("%d ", parent[i][j]);
//            }
//            printf("\n");
//        }

        memset(visited, 0, sizeof(visited));
        deque<int>dq;
        vector<int>search;
        dq.push_back(1);
        visited[1] = true;
        while(!dq.empty()){
            int cur = dq.front();
            dq.pop_front();
            search.push_back(cur);
            for(int next : graph[cur]){
                if(!visited[next]){
                    visited[next] = true;
                    dq.push_back(next);
                }
            }
        }
        ll res = 0;
        for(int i=0; i<search.size()-1; ++i){
            int idx = lca(search[i], search[i+1]);
            res += depth[search[i]] - depth[idx];
            res += depth[search[i+1]] - depth[idx];
        }

        printf("#%d %lld\n",test_case, res);

    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}