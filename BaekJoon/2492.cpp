#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N, M, T, K, x, y;
	cin >> N >> M >> T >> K;
	vector<pii> v;

	for (int i = 0; i < T; ++i) {
		cin >> x >> y;
		v.push_back({ x, y });
	}
	pii ansp = { 0,0 };
	int ans = 0;
	for (int i = 0; i < T; ++i) {
		for (int j = 0; j < T; ++j) {
			int nx, ny;
			if (v[i].first + K > N) {
				nx = N - K;
			}
			else {
				nx = v[i].first;
			}
			if (v[j].second + K > M) {
				ny = M - K;
			}
			else {
				ny = v[j].second;
			}
			int cnt = 0;
			for (pii p : v) {
				if (nx <= p.first && p.first <= nx + K && ny <= p.second && p.second <= ny + K) {
					cnt += 1;
				}
			}
			if (cnt > ans) {
				ansp = { nx, ny+K };
				ans = cnt;
			}
		}
	}
	cout << ansp.first << " " << ansp.second << '\n';
	cout << ans<<'\n';
	return 0;
}