#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N, M, K, X, ts, td;
	cin >> N >> M >> K >> X;
	vector<vector<int>> v(N + 1);
	for (int i = 0; i < M; ++i) {
		cin >> ts >> td;
		v[ts].emplace_back(td);
	}
	priority_queue<ll, vector<ll>, greater<ll>>pq;
	vector<int>visited(N + 1, 2e9);
	visited[X] = 0;
	pq.push(X);
	while (!pq.empty()) {
		int src = pq.top();
		pq.pop();
		for (int i = 0; i < v[src].size(); ++i) {
			int nxt = v[src][i];
			if (visited[nxt] > visited[src] + 1) {
				visited[nxt] = visited[src] + 1;
				pq.push(nxt);
			}
		}
	}
	bool flag = false;
	for (int i = 0; i < N + 1; ++i) {
		if (	visited[i] == K) {
			cout << i << endl;
			flag = true;
		}
	}
	if (!flag) cout << -1 << endl;
	return 0;
}
