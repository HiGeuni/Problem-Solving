#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
vector<vector<char>>map_(21, vector<char>(21));
map<char, bool> chk;
int n, m;
int ans = 0;

void go(int x, int y, int cnt){
//    cout<<x<<" "<<y;
    ans = max(ans, cnt);
//    if(!(x == 0 && y == 0) && chk[map_[x][y]]){ return; }
    for(int i=0;i<4; ++i){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx >= 0 && nx < n && ny >= 0 && ny < m && !chk[map_[nx][ny]]){
//            cout<<map_[nx][ny]<<endl;
            chk[map_[nx][ny]] = true;
            go(nx, ny, cnt+1);
            chk[map_[nx][ny]] = false;
        }
    }
}

int main(){
    cin.tie();
    cin>>n>>m;

    for(int i=0;i<n; ++i){
        for(int j=0; j<m; ++j){
            cin>>map_[i][j];
        }
    }
    for(int i=0;i<26; ++i) {
        chk[char(65 + i)] = false;
    }
    chk[map_[0][0]] = true;
    go(0,0,1);
    cout<<ans;
    return 0;
}