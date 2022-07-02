#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, m, tmp, qa, qb;
	cin >> n >> m;
	vector<int>v(n), psum(n + 1);
	psum[0] = 0;
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		psum[i + 1] = psum[i] + v[i];
	}
	for (int i = 0; i < m; ++i) {
		cin >> qa >> qb;
		cout << psum[qb] - psum[qa - 1] << '\n';
	}
	return 0;
}
