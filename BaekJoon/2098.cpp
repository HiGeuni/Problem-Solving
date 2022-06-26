#include<bits/stdc++.h>
using namespace std;

int n, mask;
vector<vector<int>>v, visited;

int tsp(int cur, int check) {
	if (check == mask) 
		return v[cur][0] ? v[cur][0] : 2e9;
	
	if (visited[cur][check] != -1) return visited[cur][check];
	visited[cur][check] = 2e9;

	for (int i = 0; i < n; ++i) {
		if (check & 1 << i || v[cur][i] == 0 ) continue;
		visited[cur][check] = min(visited[cur][check], tsp(i, check | 1 << i) + v[cur][i]);
	}
	return visited[cur][check];
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	mask = (1 << n ) - 1;
	v.resize(n, vector<int>(n));
	visited.resize(n, vector<int>((1<<16), -1));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			cin >> v[i][j];
	int ans = tsp(0, 1);
	cout << ans << '\n';
	return 0;
}
