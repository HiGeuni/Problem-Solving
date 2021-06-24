#include<cstdio>
#include<vector>
#include<queue>
#include<cmath>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;

//오른쪽이랑 아래쪽으로만 검사
const int dx[4] = {1,0, -1,0};
const int dy[4] = {0,1,0,-1};

int main(){
    int n, L, R;
    int ans = 0;
    scanf("%d%d%d", &n, &L, &R);
    vector<vector<int>>v(n, vector<int>(n));
    for(int i=0;i<n; ++i){
        for(int j=0;j<n; ++j){
            scanf("%d", &v[i][j]);
        }
    }
    while(1) {
        vector<vector<bool>> chk(n, vector<bool>(n, false));
        bool open = false;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if(chk[i][j]) continue;
                bool canMove = false;
                for(int k=0;k<4; ++k){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    if (nx >= 0 && nx < n && ny >= 0 && ny < n){
                        int tmp = abs(v[i][j] - v[nx][ny]);
                        if(tmp >= L && tmp <= R && !chk[nx][ny]){
                            open = true;
                            canMove = true;
                            break;
                        }
                    }
                }
                if(canMove){
                    deque<pii>dq;
                    deque<pii>ls;
                    dq.push_back({i,j});
                    ls.push_back({i,j});
                    int tmpCnt = 0;
                    int tmpPeople = 0;
                    chk[i][j] = true;
                    while(!dq.empty()){
                        pair<int,int> cur = dq.front();
                        dq.pop_front();
                        tmpCnt += 1;
                        tmpPeople += v[cur.first][cur.second];
                        for(int l=0; l<4; ++l){
                            int nx = cur.first + dx[l];
                            int ny = cur.second + dy[l];
                            if (nx >= 0 && nx < n && ny >= 0 && ny < n){
                                int tmp2 = abs(v[cur.first][cur.second] - v[nx][ny]);
                                if(tmp2 >= L && tmp2 <= R && !chk[nx][ny]){
                                    chk[nx][ny] = true;
                                    dq.push_back({nx, ny});
                                    ls.push_back({nx, ny});
                                }
                            }
                        }
                    }
                    int value = tmpPeople/tmpCnt;
                    while(!ls.empty())
                    {
                        pii cur = ls.front();
                        ls.pop_front();
                        v[cur.first][cur.second] = value;
                    }
                }else{
                    continue;
                }
            }
        }
        if(!open) break;
        else{
            ans += 1;
        }
    }
    printf("%d", ans);
    return 0;
}
