#include<bits/stdc++.h>
using namespace std;

vector<int>w;
vector<vector<int>>v;
vector<vector<int>>dp;
vector<bool>visited;

void dfs(int x) {
	visited[x] = true;
	dp[x][1] = w[x];
	for (int i = 0; i < v[x].size(); ++i) {
		int nxt = v[x][i];
		if (!visited[nxt]){
			dfs(nxt);
			dp[x][1] += dp[nxt][0];
			dp[x][0] += max(dp[nxt][1], dp[nxt][0]);
		}
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, src, dst;
	cin >> n;
	w.resize(n+1);
	v.resize(n+1);
	dp.resize(n+1, vector<int>(2, 0));
	visited.resize(n+1, false);
	for(int i=1; i<=n; ++i)
		cin>>w[i];
	for (int i = 0; i < n-1; ++i) {
		cin >> src >> dst;
		v[src].push_back(dst);
		v[dst].push_back(src);
	}
	dfs(1);
	cout << max(dp[1][0], dp[1][1])<<'\n';
	return 0;
}
