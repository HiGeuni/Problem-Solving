#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int>pii;

vector<vector<pii>>v;


vector<int> dijkstra(int start, int n) {
	vector<int>visited(n+1, 2e9);
	visited[start] = 0;
	priority_queue<pii>pq;
	pq.push(make_pair(0, start));

	while (!pq.empty()) {
		int cur = pq.top().second;
		int weight = -1 * pq.top().first;
		pq.pop();
		if (visited[cur] < weight) continue;
		for (int i = 0; i < v[cur].size(); i++) {
			int next_weights = visited[cur] + v[cur][i].second;
			int before_change = visited[v[cur][i].first];

			if (next_weights < before_change) {
				visited[v[cur][i].first] = next_weights;
				pq.push({ -1 * next_weights, v[cur][i].first });
			}
		}
	}
	return visited;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, m, s, d, w, x;
	cin >> n >> m >> x;
	v.resize(n + 1);

	for (int i = 0; i < m; ++i) {
		cin >> s >> d >> w;
		v[s].push_back({ d, w });
	}
	vector<int>ans(n + 1,0);
	for (int i = 1; i < n + 1; ++i) {

		vector<int>visited = dijkstra(i, n);
		if (i == x) {
			for (int j = 1; j < n + 1; ++j) {
				ans[j] += visited[j];
			}
		}
		else {
			ans[i] += visited[x];
		}
	}
	int a = 0;
	for (int i = 1; i < n+1; ++i) {
		a = max(a, ans[i]);
	}
	cout << a;
	return 0;
}
