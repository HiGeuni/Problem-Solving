#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int>pii;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N, M, val, diff;
	cin>>N>>M;
	vector<vector<int>>ori(N, vector<int>(M));
	vector<vector<int>>chg(N,vector<int>(M));
	vector<vector<int>>visited(N,vector<int>(M, 0));
	vector<pii>p;
	bool flag = true;
	for(int i=0; i<N; ++i)
		for(int j=0; j<M; ++j)
			cin>>ori[i][j];

	for(int i=0; i<N; ++i){
		for(int j=0; j<M; ++j){
			cin>>chg[i][j];
			if(ori[i][j] != chg[i][j]){
				p.push_back({i, j});
				diff = ori[i][j] - chg[i][j];
				val = ori[i][j];
			}
		}
	}
	
	if(p.size() == 0){
		cout<<"YES"<<endl;
	}else{
		deque<pii>q;
		q.push_back(p[0]);
		visited[p[0].first][p[0].second] = 1;
		while(!q.empty()){
			pii cur = q.front(); q.pop_front();
			for(int i=0; i<4; ++i){
				int nx = cur.first + dx[i];
				int ny = cur.second + dy[i];
				if(nx >= 0 && nx < N && ny >= 0 && ny < M){
					if(visited[nx][ny] == 0 && ori[nx][ny] == ori[cur.first][cur.second]){
						if(ori[nx][ny] - chg[nx][ny] == diff){
							q.push_back({nx, ny});
							visited[nx][ny] = 1;
						}else{
							flag = false;
							break;
						}
					}
				}
			}
		}
		int cnt = 0;
		for(int i=0; i<N; ++i){
			for(int j=0; j<M; ++j){
				if(visited[i][j] == 1)
					cnt += 1;
			}
		}
		cout<<(flag && cnt == p.size() ? "YES" : "NO")<<endl;
	}
	return 0;
}
