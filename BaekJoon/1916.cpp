#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int>pii;

vector<vector<pii>>v;
vector<int>visited;

void dijkstra(int start, int end) {
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
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, m, s, d, w, start, end;
	cin >> n >> m;
	v.resize(n + 1);
	visited.resize(n + 1, 2e9);
	for (int i = 0; i < m; ++i) {
		cin >> s >> d >> w;
		v[s].push_back({ d, w });
	}
	cin >> start >> end;
	visited[start] = 0;
	dijkstra(start, end);
	cout << visited[end];
	return 0;
}
