#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, k, ans = -2e9, t = 0;
	cin >> n >> k;
	vector<int>v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
		if (i < k) t += v[i];
	}
	ans = t;
	for (int i = k; i < n; ++i) {
		t -= v[i - k];
		t += v[i];
		ans = max(ans, t);
	}
	cout << ans;
	return 0;
}
