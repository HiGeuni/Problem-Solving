#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll N, B;

vector<vector<int>>m;

vector<vector<int>> calculate_matrix(vector<vector<int>>t1, vector<vector<int>>t2) {
	vector<vector<int>>ans(N, vector<int>(N, 0));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			for (int k = 0; k < N; ++k) {
				ans[i][j] += t1[i][k] * t2[k][j];
			}
			ans[i][j] %= 1000;
		}
	}
	return ans;
}

vector<vector<int>> dnq(ll b) {
	if (b == 1) {
		return m;
	}
	vector<vector<int>> t = dnq(b / 2);
	t = calculate_matrix(t, t);
	if (b & 1) {
		t = calculate_matrix(t, m);
	}
	return t;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(0);
	cin >> N >> B;
	m.resize(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> m[i][j];
			m[i][j] %= 1000;
		}
	}
	vector<vector<int>> ans = dnq(B);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cout << ans[i][j] << ' ';
		}
		cout << endl;
	}

	return 0;
}
