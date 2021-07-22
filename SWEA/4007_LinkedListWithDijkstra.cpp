#include<iostream>
#include<utility>
#include<queue>
#include<vector>
#include<algorithm>
#include<list>
using namespace std;
typedef pair<int,int> pii;

struct Node{
    int to;
    int weight;
    Node * next;
    Node * tail;
};

Node node[2][550001];
int nodeCount[2] = {0,0};

void init(){
    nodeCount[0] = 0;
    nodeCount[1] = 0;
}

void makeHead(int idx){
    node[idx][nodeCount[idx]].weight = -1;
    node[idx][nodeCount[idx]].to = (nodeCount[idx]) + 1;
    node[idx][nodeCount[idx]].tail = nullptr;
    node[idx][nodeCount[idx]++].next = nullptr;
}

void pushNum(int from, int to, int weight, int idx){
    node[idx][nodeCount[idx]].to = to;
    node[idx][nodeCount[idx]].weight = weight;
    node[idx][nodeCount[idx]].tail = nullptr;
    node[idx][nodeCount[idx]++].next = nullptr;
    Node * ptr = node[idx][from-1].tail;
    if(!ptr){
        node[idx][from-1].next = &node[idx][(nodeCount[idx])-1];
        node[idx][from-1].tail = &node[idx][(nodeCount[idx])-1];
    }else{
        ptr->next = &node[idx][(nodeCount[idx])-1];
        node[idx][from-1].tail = &node[idx][(nodeCount[idx])-1];
    }
}

//if flag == 0, graph1, flag == 1, graph2
void dijkstra(int start, vector<int>& dist,vector<bool>&visited, int idx){
    dist[start] = 0;
    priority_queue<pii, vector<pii>, greater<pii>>pq;
    pq.push({0, start});
    while(!pq.empty()){
        int curNode = pq.top().second;
        int curCost = pq.top().first;
        pq.pop();
        visited[curNode] = true;
        Node * tmp = node[idx][curNode-1].next;
        while(tmp){
            int nextNode = tmp->to;
            if(visited[nextNode]){
                tmp = tmp->next;
                continue;
            }
            int nextCost = tmp->weight + curCost;
            if(nextCost < dist[nextNode]){
                dist[nextNode] = nextCost;
                pq.push({nextCost, nextNode});
            }
            tmp = tmp->next;
        }
    }
}

int main(){
    cin.tie();
    ios_base::sync_with_stdio(false);
    int Tc;
    cin>>Tc;
    for(int tc=1; tc<=Tc; ++tc){
        init();
        int N, M, X, u, v, w;
        cin>>N>>M>>X;
        for(int i=0;i<N; ++i){
            // two graphs
            makeHead(0);
            makeHead(1);
        }
        //make Graph
        for(int i=0;i<M; ++i){
            cin>>u>>v>>w;
            //two graphs
            pushNum(u, v, w, 0);
            pushNum(v, u, w, 1);
        }
        vector<int>dist1(N+1, 2e9);
        vector<bool>visited(N+1, false);
        dijkstra(X, dist1,visited, 0);
        vector<bool>visited2(N+1, false);
        vector<int>dist2(N+1, 2e9);
        dijkstra(X, dist2,visited2,  1);
        int ans = 0;
        for(int i=1;i<N+1; ++i){
            if(dist1[i] == 2e9 || dist2[i] == 2e9) continue;
            ans = max(ans, dist1[i] + dist2[i]);
        }
        cout<<"#"<<tc<<" "<<ans<<endl;
    }
    return 0;
}