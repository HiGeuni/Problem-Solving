#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
vector<vector<int>>map;
vector<vector<bool>>visited;
int ans = 0;
int N;

const int dx[] = {1,-1,0,0,1,1,-1,-1};
const int dy[] = {0,0,-1,1,-1,1,1,-1};

void dfs(int i, int j){
    for(int k=0;k<8; ++k){
        int nx = i + dx[k];
        int ny = j + dy[k];
        if(nx >=0 && nx < N && ny >= 0 && ny < N){
            if(!visited[nx][ny]){
                visited[nx][ny] = true;
                if(map[nx][ny] == 0){
                    dfs(nx, ny);
                }
            }
        }
    }
}

int main(){
    int tc;
    cin>>tc;

    for(int testCase = 1; testCase <tc+1; ++testCase){
        cin>>N;
        for(int i=0; i<map.size(); ++i){
            map.clear();
            visited.clear();
        }
        map.resize(N, vector<int>(N, 0));
        visited.resize(N, vector<bool>(N, false));
        vector<string>s;
        for(int i=0;i<N; ++i){
            string tmp;
            cin>>tmp;
            s.push_back(tmp);
        }
        int nx;
        int ny;
        //calculate
        for(int i=0;i<N; ++i){
            for(int j=0;j<N; ++j){
                if(s[i][j] == '.'){
                    for(int k=0;k<8; ++k){
                        nx = i + dx[k];
                        ny = j + dy[k];
                        if(nx >= 0 && nx < N && ny >= 0 && ny < N){
                            if(s[nx][ny] == '*'){
                                map[i][j] += 1;
                            }
                        }
                    }
                }else{
                    map[i][j] = -1;
                    visited[i][j] = true;
                }
            }
        }
        ans =0;
        for(int i=0;i<N; ++i){
            for(int j=0;j<N; ++j){
                if(!visited[i][j] && map[i][j] == 0){
                       ans += 1;
                       visited[i][j] = true;
                       dfs(i, j);
                }
            }
        }
        //remain things, must click once
        for(int i=0;i<N; ++i){
            for(int j=0;j<N; ++j){
                if(!visited[i][j]) ans += 1;
            }
        }
    }
    return 0;
}