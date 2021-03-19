#include<bits/stdc++.h>
using namespace std;

int main(){
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    int n,m;
    cin>>n>>m;
    vector<vector<int>>v(m, vector<int>(n));
    vector<vector<bool>>visited(m, vector<bool>(n));
    for(int i=0; i<n; ++i)
        for(int j=0; j<m; ++j)
            cin>>v[j][i];

    int tmp, cnt = 0;
    int ans = -1;
    for(int i=0; i<n; ++i){
        for(int j=0; j<m; ++j){
            if(v[j][i] == 1 && !visited[j][i]){
                visited[j][i] = true;
                tmp = 1;
                cnt+=1;
                deque<pair<int,int>>dq;
                dq.push_back({j, i});
                while(dq.size()){
                    pair<int,int>cur = dq.back();
                    dq.pop_back();
                    for(int k=0; k<4; ++k){
                        int nx = dx[k] + cur.first;
                        int ny = dy[k] + cur.second;
                        if((0<=nx && nx<m) && (0<=ny && ny<n) && v[nx][ny] == 1 && !visited[nx][ny]){
                            visited[nx][ny] = true;
                            dq.push_back({nx,ny});
                            tmp += 1;
                        }
                    }
                }
                ans = max(ans, tmp);
            }
        }
    }
    if(cnt==0){
        cout<<0<<'\n'<<0;
    }else {
        cout << cnt << '\n' << ans;
    }
    return 0;
}
