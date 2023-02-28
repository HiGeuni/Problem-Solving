#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	ll N, M, t, ans = 0;
	cin >> N >> M;
	vector<ll>judge(N);
	for (int i = 0; i < N; ++i) {
		cin >> judge[i];
	}
	sort(judge.begin(), judge.end());
	ll l = 1, r = judge[N-1] * M;
	while (l <= r) {
		ll mid = (l + r) / 2;
		ll tmp = 0;
		for (int i = 0; i < N; ++i) {
			if (tmp > M) break;
			tmp += (mid / judge[i]);
		}
		if (tmp < M) {
			l = mid + 1;
		}
		else {
			ans = mid;
			r = mid - 1;
		}
	}
	cout << ans << endl;
	return 0;
}
