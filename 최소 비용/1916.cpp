#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<utility>
using namespace std;
#define MAX 2e9
typedef pair<int, int> P;
vector<P>d[300100];
int n, m, x, res = 0;
int u, v, w, dst;
vector<int>dis(20001);
void dijkstra();

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m;i++) {
		cin >> u >> v >> w;
		d[u].push_back(make_pair(v, w));
	}
	cin>>x>>dst;
	for (int i = 1; i <= n; i++) {
		dis[i] = MAX;
	}
	dis[x] = 0;
	dijkstra();
	cout<<dis[dst];
	return 0;
}

void dijkstra() {
	priority_queue<P>pq;
	pq.push(make_pair(0, x));

	while (!pq.empty()) {
		int cur = pq.top().second;
		int weight = -1 * pq.top().first;
		pq.pop();

		for (int i = 0; i < d[cur].size(); i++) {
			int val = dis[cur]+d[cur][i].second;
			int be_val = dis[d[cur][i].first];
			if (val < be_val) {
				dis[d[cur][i].first] = val;
				pq.push({ -1 * val, d[cur][i].first });
			}
		}

	}
}
