#include <string>
#include <vector>
#include<algorithm>
#include<iostream>
using namespace std;

bool visited[8] = {false, };
int c = 0;

void dfs(int rem, vector<vector<int>> dungeons, int cnt){
    c = max(cnt, c);
    for(int i=0; i<dungeons.size(); ++i){
        if(visited[i]){
            continue;
        }else{
            if(rem - dungeons[i][0] >= 0){
                visited[i] = true;
                dfs(rem-dungeons[i][1], dungeons, cnt + 1);
                visited[i] = false;
            }else{
                continue;
            }
        }
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    dfs(k, dungeons, 0);
    return c;
}
