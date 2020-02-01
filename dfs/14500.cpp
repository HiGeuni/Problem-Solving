//depth == 3인 dfs

#include<bits/stdc++.h>
using namespace std;

int r, c;
bool visited[501][501];
int arr[501][501];
const int dx[4] = {0,0,-1,1};
const int dy[4] = {1,-1, 0,0};

int dfs(int x, int y, int depth){
	if(depth == 4) return 0;
	int ans = 0;
	for(int i=0; i<4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx<0 || ny<0 || nx>=r || ny>=c)
			continue;
		//if(visited[nx][ny] == true) continue;
		//ans = max(ans, dfs(nx,ny,depth+1)+arr[x][y]);
		//visited[nx][ny] = false;
		if(visited[nx][ny] == false){
			visited[nx][ny] = true;
			ans = max(ans, dfs(nx,ny,depth+1)+arr[x][y]);
			visited[nx][ny] = false;
		}
	}
	return ans;
}

int special(int x, int y){
	int ans = 0;
	//case 1 x+1,y x+2,y x+1,y-1 ㅜ
	if(x<r-2 && y>0)
		ans = max(ans, arr[x+1][y] + arr[x+2][y] + arr[x+1][y-1]+ arr[x][y]);
	//case 2 x+1,y x+1,y+1 x+1,y-1 ㅓ
	if(x<r-1 && y<c-1 && y>0)
		ans = max(ans, arr[x+1][y]+ arr[x+1][y+1]+ arr[x+1][y-1]+ arr[x][y]);
	
	//case 3 x+1,y x+2,y x+1,y+1 ㅗ
	if(x<r-2 && y<c-1)
		ans = max(ans, arr[x+1][y]+ arr[x+2][y]+ arr[x+1][y+1]+ arr[x][y]);

	//case 4 x,y+1 x,y x,y-1 x+1,y ㅏ
	if(y>0 && y+1<c && x+1<r)
		ans = max(ans, arr[x][y+1]+arr[x][y-1] + arr[x+1][y] + arr[x][y]);

	return ans;
}

int main(){
	cin.tie();
	int ans = 0;
	cin>>r>>c;
	for(int i=0; i<r; ++i)
		for(int j=0; j<c; ++j)
			cin>>arr[i][j];
	for (int i=0; i<r; ++i){
		for(int j=0; j<c; ++j){
			visited[i][j] = true;
			ans = max(dfs(i, j, 0), ans);
			ans = max(special(i,j), ans);
			visited[i][j] = false;
		}
	}
	cout<<ans;
	return 0;
}
