#include<bits/stdc++.h>
using namespace std;

int dp[501][501];
int arr[501][501];
const int dx[4] = {0,0,1,-1};
const int dy[4] = {1,-1, 0, 0};
int n;

int dfs(int x, int y){
	int nx, ny;
	//중복제거
	if(dp[x][y] != 0) return dp[x][y];
	dp[x][y] = 1;
	for(int i=0; i<4; i++){
		nx = dx[i] + x;
		ny = dy[i] + y;
		if(nx>=n||ny>=n||nx<0||ny<0)
			continue;
		//가려는 곳의 대나무가 더 적을 때
		if(arr[nx][ny] <= arr[x][y])
			continue;
		dp[x][y] = max(dp[x][y], dfs(nx,ny)+1);
	}
	return dp[x][y];
}

int main(){
	cin>>n;
	int ans = -2e9;
	for(int i=0; i<n; i++){
		for(int j=0 ;j<n; j++){
			cin>>arr[j][i];
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			ans = max(ans, dfs(j, i));
		}
	}
	cout<<ans;
}
