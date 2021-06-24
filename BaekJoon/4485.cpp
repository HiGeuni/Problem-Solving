#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;

const int dx[4] = {1,-1,0,0};
const int dy[4] = {0,0,1,-1};

struct node{
    int weight;
    int x;
    int y;
};

struct compare{
    bool operator()(node n1, node n2){
        return n1.weight > n2.weight;
    }
};

int main(){
    int n;
    int cnt =0;
    while(true){
        cnt +=1;
        scanf("%d", &n);
        vector<vector<node>>v(n, vector<node>(n));
        vector<vector<int>>visit(n, vector<int>(n));
        if(n == 0) break;
        //input
        for(int i=0;i<n; ++i){
            for(int j=0;j<n; ++j){
                visit[i][j] = 2e9;
                scanf("%d", &v[i][j].weight);
                v[i][j].x = j;
                v[i][j].y = i;
            }
        }
        priority_queue<node,vector<node>, compare>pq;
        pq.push(v[0][0]);
        visit[0][0] = v[0][0].weight;
        while(!pq.empty()){
            node cur = pq.top();
            pq.pop();
            for(int i=0;i<4; ++i){
                int nx = cur.x + dx[i];
                int ny = cur.y + dy[i];
                if(nx >=0 && nx < n && ny >= 0 && ny < n){
                    if(visit[cur.y][cur.x] + v[ny][nx].weight < visit[ny][nx]){
                        pq.push(v[ny][nx]);
                        visit[ny][nx] = visit[cur.y][cur.x] + v[ny][nx].weight;
                    }
                }
            }
        }
        printf("Problem %d: %d\n",cnt, visit[n-1][n-1]);
    }
    return 0;
}