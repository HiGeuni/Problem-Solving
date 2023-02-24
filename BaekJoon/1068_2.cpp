#include<bits/stdc++.h>
using namespace std;

int N;
vector<int>parent[50];
vector<int>visited;
int erase;
int _root;
int ans = 0;

void dfs(int n) {
	if (!parent[n].size()) {
		ans += 1; return;
	}
	if (parent[n].size() == 1 && erase == parent[n][0]){
		ans += 1;return ;
		}
	for (int i = 0; i < parent[n].size(); ++i) {
		int next = parent[n][i];
		if (!visited[next] && erase != next) {
			visited[next] = true;
			dfs(next);
		}
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	cin >> N;
	int cnt = 0, t;
	for (int i = 0; i < N; ++i) {
		cin >>t;
		if (t == -1) {
			_root = i;
		}
		else {
			parent[t].push_back(i);
		}

	}
	cin >> erase;

	if (erase != _root) {
		visited.resize(N, false);
		visited[_root] = true;
		dfs(_root);
	}
	cout << ans;
	return 0;
}
