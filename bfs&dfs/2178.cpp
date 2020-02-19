//2178 미로탐색
//20200219

#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

const int dx[4] = {0,0,1,-1};
const int dy[4] = {1,-1,0,0};
int chk[101][101];


void bfs(int x, int y, int max_x,int max_y, vector<vector<int>>&v){
	int nx,ny;
	queue<pii>q;
	q.push(make_pair(x,y));
	chk[y][x] = 1;
	while(!q.empty()){
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for(int i=0; i<4; ++i){
			nx = x + dx[i];
			ny = y + dy[i];
			if(nx>=0 && ny>=0 && nx<max_x && ny<max_y){
				if(chk[ny][nx] == 0 && v[ny][nx] ==1){
					q.push(make_pair(nx, ny));
					chk[ny][nx] = chk[y][x] +1;
				}
			}
		}
		
	}
	
}

int main(){
	int n, m, res;
	cin>>n>>m;
	vector<vector<int>> v(m, vector<int>(n));
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			scanf("%1d", &v[j][i]);
		}
	}
	bfs(0,0, n, m, v);
	cout<<chk[m-1][n-1];
	return 0;
}
