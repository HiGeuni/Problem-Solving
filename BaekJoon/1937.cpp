#include<iostream>
#include<algorithm>
using namespace std;

const int dx[4] = { 0,0,1,-1 };
const int dy[4] = { 1,-1,0,0 };
int arr[510][510];
int dp[510][510];
int n, ans=-1;

int dfs(int x, int y) {
	if (dp[y][x]) return dp[y][x];
	dp[y][x] = 1;
	int & ref = dp[y][x];
	for (int i = 0; i < 4; ++i) {
		int nx = dx[i] + x;
		int ny = dy[i] + y;
		if (nx < 0 || ny < 0 || nx >= n || ny >= n) continue;
		if (arr[y][x] >= arr[ny][nx]) continue;
		dp[y][x] = max(dp[y][x], dfs(nx, ny)+1);
	}
	return dp[y][x];
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	cin >> n;
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> arr[j][i];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j) 
			ans = max(ans, dfs(j, i));

	cout << ans << endl;
	return 0;
}
