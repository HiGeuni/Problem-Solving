#include<bits/stdc++.h>
using namespace std;

int N;
vector<string>v;

void dnq(int n, int sx, int sy) {
	// check one or zero
	char t = v[sx][sy];
	bool flag = true;
	for (int i = sx; i < sx + n; ++i) {
		for (int j = sy; j < sy + n; ++j) {
			if (v[i][j] != t) {
				flag = false;
			}
		}
	}
	if (flag) {
		cout << t;
	}
	else {
		cout << "(";
		dnq(n / 2, sx, sy);
		dnq(n / 2, sx, sy + n / 2);
		dnq(n / 2, sx + n/2, sy);
		dnq(n / 2, sx+n/2, sy+n/2);
		cout << ")";
	}
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> v[i];
	}
	dnq(N, 0, 0);
	return 0;
}
