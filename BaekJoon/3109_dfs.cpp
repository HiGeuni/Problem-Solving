#include<iostream>
#include<vector>
#include<string>
using namespace std;

int R, C;
vector<vector<int>>visited(10001, vector<int>(501, 0));
vector<string>map;
int dr[3] = {-1,0,1};
bool recurFlag = true;
int cnt = 0;

void dfs(int r,int c){
    if(!recurFlag) return;
    if(visited[r][c]!=0) return;
    visited[r][c] = c;
    if(c == C-1){
        recurFlag = false;
        cnt++;
    }
    for(int i=0; i<3; ++i){
        int nr = r + dr[i];
        int nc = c + 1;
        if(0<=nr && nr < R && 0<= nc && nc < C && map[nr][nc] !='x' && visited[nr][nc] == 0){
            dfs(nr, nc);
        }
    }
}

int main(){
    cin>>R>>C;
    for(int i=0;i<R; ++i){
        string s;
        cin>>s;
        map.push_back(s);
    }

    for(int i=0;i<R; ++i){
        recurFlag = true;
        dfs(i, 0);
    }
//    int ans = 0;
//    for(int i=0;i<R; ++i){
//        ans = max(ans, visited[i][C-1]);
//    }
    cout<<cnt;
}