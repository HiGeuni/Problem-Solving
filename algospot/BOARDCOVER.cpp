#include<bits/stdc++.h>
using namespace std;

const int dir[4][3][2] = {
        {{0,0},{1,0},{0,1}},
        {{0,0},{1,0},{1,1}},
        {{0,0},{0,1},{1,1}},
        {{0,0},{1,0},{1,-1}}
};
int nx, ny;

int solve(vector<vector<char>>&v){
    int x = -1, y = -1;
    for(int i=0;i<nx; ++i){
        for(int j=0;j<ny; ++j){
            if(v[i][j] == '.') {
                x = i;
                y = j;
                break;
            }
        }
        if(x != -1) break;
    }
    if(y == -1) return 1;
    int ret = 0;
    for(int i=0;i<4; ++i){
        bool flag = true;
        for(int j=0;j<3; ++j){
            if(!flag) break;
            int tx = x + dir[i][j][0];
            int ty = y + dir[i][j][1];
            if(tx < 0 || ty < 0 || tx>=nx || ty>=ny || v[tx][ty] == '#'){
                flag = false;
            }
        }
        if(flag){
            for(int j=0;j<3; ++j){
                int tx = x + dir[i][j][0];
                int ty = y + dir[i][j][1];
                v[tx][ty] = '#';
            }
            ret += solve(v);
            for(int j=0;j<3; ++j){
                int tx = x + dir[i][j][0];
                int ty = y + dir[i][j][1];
                v[tx][ty] = '.';
            }
        }
    }
    return ret;
}

int main(){
    cin.tie(0);
    int tc;
    cin>>tc;
    for(int i=0;i<tc; ++i){
        cin>>nx>>ny;
        vector<vector<char>>v(nx, vector<char>(ny, '.'));
        for(int i=0;i<nx; ++i)
            for(int j=0;j<ny; ++j)
                cin>>v[i][j];
        cout<<solve(v)<<'\n';
    }
    return 0;
}