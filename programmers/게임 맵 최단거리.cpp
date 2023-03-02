#include<vector>
#include<deque>
using namespace std;

typedef pair<int, int> pii;


int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int w = maps.size();
    int h = maps[0].size();
    vector<vector<int> >visited(maps.size(), vector<int>(maps[0].size()));
    deque<pii>dq;
    dq.push_back({0,0});
    visited[0][0] = 1;
    while(!dq.empty()){
        pii cur = dq.front();
        dq.pop_front();
        int cur_x = cur.first;
        int cur_y = cur.second;
        for(int i=0; i<4; ++i){
            int nx = cur_x + dx[i];
            int ny = cur_y + dy[i];
            if(0<=nx && nx <w && 0<=ny && ny <h &&maps[nx][ny] == 1 && visited[nx][ny] == 0){
                visited[nx][ny] = visited[cur_x][cur_y] + 1;
                dq.push_back({nx, ny});
            }
        }
    }
    answer = visited[w-1][h-1] ? visited[w-1][h-1] : -1;
    return answer;
}
