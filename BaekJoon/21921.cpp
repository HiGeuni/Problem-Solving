#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int X, N;
	cin >> X >> N;
	vector<int>v(X);
	int tsum = 0;
	int ttsum = 0;
	for (int i = 0; i < X; ++i) {
		cin >> v[i];
		if (i < N) tsum += v[i];
	}
	ttsum = tsum;
	int max_ = tsum;
	for (int i = 0; i < X - N; ++i) {
		tsum -= v[i];
		tsum += v[i + N];
		if (max_ < tsum) {
			max_ = tsum;
		}
	}
	int cnt = 0;
	if (ttsum == max_) cnt += 1;
	for (int i = 0; i < X - N; ++i) {
		ttsum -= v[i];
		ttsum += v[i + N];
		if (ttsum == max_) {
			cnt += 1;
		}
	}
	if (max_ == 0) {
		cout << "SAD" << '\n';
	}
	else {
		cout << max_ << '\n' << cnt<<'\n';
	}
	return 0;
}
