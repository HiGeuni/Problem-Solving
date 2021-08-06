#include<cstdio>
#include<queue>
#include<algorithm>
#include<vector>
#include<utility>
#include<cstring>
using namespace std;
const int dx[] = {1,-1,0,0};
const int dy[] = {0,0,1,-1};
int map[101][101];
int visited[101][101];

struct node{
    int weight, x, y;
};

struct compare{
    bool operator()(node & a, node & b){
        return a.weight > b.weight;
    }
};


int main(){
    int tc;
    scanf("%d", &tc);
    for(int Tc=1; Tc<=tc; ++Tc){
        priority_queue<node, vector<node>, compare>pq;
        int N;
        scanf("%d", &N);
        fill(&map[0][0], &map[N][N], 0);
        fill(&visited[0][0], &visited[N][N], 2e9);
        for(int i=0; i<N; ++i)
            for(int j=0; j<N; ++j)
                scanf("%1d", &map[i][j]);

        visited[0][0] = map[0][0];
        pq.push({map[0][0],0,0});
        while(!pq.empty()){
            node cur = pq.top();
            pq.pop();
            int weight = cur.weight;
            int curX = cur.x;
            int curY = cur.y;
            if(curX == N-1 && curY == N-1){
                visited[N-1][N-1] = weight;
                break;
            }
            for(int i=0; i<4; ++i){
                int nx = curX + dx[i];
                int ny = curY + dy[i];
                if(0<= nx && nx < N && 0<= ny && ny <N){
                    if(visited[nx][ny] > weight + map[nx][ny]){
                        visited[nx][ny] = weight + map[nx][ny];
                        pq.push({weight + map[nx][ny], nx, ny});
                    }
                }

            }
        }
        printf("#%d %d\n", Tc, visited[N-1][N-1]);
    }
    return 0;
}