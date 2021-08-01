#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef struct Balls{
    int rX, rY, bX, bY, cnt;
};
const int dx[4] = {-1,1,0,0};
const int dy[4] = {0,0,-1,1};

int main(){
    int N,M;
    string tmp;
    cin>>N>>M;
    vector<string>v;
    deque<Balls>dq;
    Balls ball = {0,0,0,0,0};
    for(int i=0;i<N; ++i){
        cin>>tmp;
        for(int j=0;j<M; ++j){
            if(tmp[j] == 'R'){
                ball.rX = i; ball.rY = j;
                tmp[j] = '.';
            }else if(tmp[j] == 'B'){
                ball.bX = i; ball.bY = j;
                tmp[j] = '.';
            }
        }
        v.push_back(tmp);
    }
    int ans = -1;

    dq.push_back(ball);
    while(!dq.empty() && ans == -1){
        Balls cur2 = dq.front(); dq.pop_front();
        if(cur2.cnt == 10) break;
        pii red = {cur2.rX, cur2.rY};
        pii blue = {cur2.bX, cur2.bY};
        cur2.cnt += 1;
        for(int i=0;i<4; ++i){
            bool dqFlag = false;
            bool flag = false;
            bool blueFlag = false;
            Balls cur = cur2;
            deque<pii>rDq; rDq.push_back(red);
            deque<pii>bDq; bDq.push_back(blue);
            while(!rDq.empty()){
                pii curBall = rDq.front();rDq.pop_front();
                int nx = curBall.first + dx[i];
                int ny = curBall.second + dy[i];
                if(nx>=0 && nx < N && ny>=0 && ny < M && v[nx][ny] != '#'){
                    cur.rX = nx;
                    cur.rY = ny;
                    dqFlag = true;
                    if(v[nx][ny]=='.'){
                        rDq.push_back({nx, ny});
                    }else if(v[nx][ny] == 'O'){
                        flag = true;
                    }
                }
            }
            while(!bDq.empty()){
                pii curBall = bDq.front();bDq.pop_front();
                int nx = curBall.first + dx[i];
                int ny = curBall.second + dy[i];
                if(nx>=0 && nx < N && ny>=0 && ny < M){
                    if(v[nx][ny]=='.'){
                        cur.bX = nx;
                        cur.bY = ny;
                        dqFlag = true;
                        bDq.push_back({nx, ny});
                    }else if(v[nx][ny] == 'O'){
                        blueFlag = true;
                    }
                }
            }

            if(cur.rX == cur.bX && cur.rY == cur.bY){
                int distA = abs((cur2.rX - cur.rX) + (cur2.rY - cur.rY));
                int distB = abs((cur2.bX - cur.bX) + (cur2.bY - cur.bY));
                if(distA > distB){
                    cur.rX -= dx[i];
                    cur.rY -= dy[i];
                }else{
                    cur.bX -= dx[i];
                    cur.bY -= dy[i];
                }
            }

            if(flag && !blueFlag){
                ans = cur2.cnt;
                break;
            }
            if(!blueFlag && dqFlag){
                dq.push_back(cur);
            }
        }
    }
    cout<< ((ans==-1) ? 0 : 1);
    return 0;
}
