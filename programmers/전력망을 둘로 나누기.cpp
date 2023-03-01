#include <string>
#include <vector>
#include<deque>
using namespace std;

int solution(int n, vector<vector<int>> wires) {
    int answer = 2e9;
    for(int i=0; i<wires.size(); ++i){
        vector<vector<int>>graph(n+1, vector<int>());
        for(int j=0; j<wires.size(); ++j){
            if(i == j) continue;
            graph[wires[j][0]].push_back(wires[j][1]);
            graph[wires[j][1]].push_back(wires[j][0]);
        }
        vector<bool>visited(n+1, false);
        int idx =0;
        int cnt[2] = {1,1};
        for(int i=1; i<n+1; ++i){
            if(!visited[i]){
                deque<int>dq;
                dq.push_back(i);
                visited[i] = true;
                while(!dq.empty()){
                    int cur = dq.front();
                    dq.pop_front();
                    for(int j=0; j<graph[cur].size(); ++j){
                        int next_node = graph[cur][j];
                        if(!visited[next_node]){
                            cnt[idx] += 1;
                            visited[next_node] = true;
                            dq.push_back(next_node);
                        }
                    }
                }
                idx += 1;
            }
        }
        answer = min(abs(cnt[0] - cnt[1]), answer);
    }
    return answer;
}
