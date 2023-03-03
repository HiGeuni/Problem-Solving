#include <string>
#include <vector>
#include <iostream>
#include <deque>

using namespace std;

typedef pair<int,int> pii;

int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<int>>visited(n, vector<int>(m, 1));
    for(int i=0; i<puddles.size(); ++i){
        int x = puddles[i][1]-1;
        int y = puddles[i][0]-1;
        visited[x][y] = 2e9;    
    }
    bool flag = false;
    for(int i=0; i<n; ++i){
        if(visited[i][0] == 2e9){
            flag = true;
        }
        if(flag) visited[i][0] = 0;
    }
    flag = false;
    for(int i=0; i<m; ++i){
        if(visited[0][i] == 2e9){
            flag = true;
        }
        if(flag) visited[0][i] = 0;
    }
    for(int i=1; i<n; ++i){
        for(int j=1; j<m; ++j){
            if(visited[i][j] == 2e9){
                visited[i][j] = 0;
            }else{
                visited[i][j] = (visited[i-1][j] + visited[i][j-1]) % 1000000007;
            }
        }
    }
    answer = visited[n-1][m-1];
    return answer;
}
