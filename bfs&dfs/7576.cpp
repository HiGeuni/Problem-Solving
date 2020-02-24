//7576 토마토
//20200224
//BFS

#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
const int dx[4] = {0,0,1,-1};
const int dy[4] = {1,-1,0,0};
bool chk[1001][1001] = {false, };
int arr[1001][1001];
int d[1001][1001];

int main(){
	cin.tie();
	ios::sync_with_stdio();
	int n,m,x,y,nx,ny, ans =0;
	cin>>m>>n;
	queue<pii>q;
	for(int i=0; i<n; ++i)
		for(int j=0; j<m; ++j){
			cin>>arr[i][j];
			if(arr[i][j]==1){
				q.push(make_pair(i,j));
				chk[i][j] = true;
				d[i][j] = 0;
			}
		}
	while(!q.empty()){
		x = q.front().first;
		y = q.front().second;
		q.pop();
		for(int i=0; i<4; ++i){
			nx = x + dx[i];
			ny = y + dy[i];
			if(chk[nx][ny] || arr[nx][ny] == -1)
				continue;
			if(nx < n && ny < m && nx >= 0 && ny >= 0){
				if(arr[nx][ny]==0){
					arr[nx][ny] = 1;
					q.push(make_pair(nx, ny));
					d[nx][ny] = d[x][y] + 1;
					ans = max(ans, d[nx][ny]);
				}
			}	
		}
	}
	/*for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			cout<<arr[i][j]<<" ";
		}
		cout<<'\n';
	}*/
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			if(arr[i][j] == 0)
				ans = -1;
		}
	}
	cout<<ans;
	return 0;	
}
