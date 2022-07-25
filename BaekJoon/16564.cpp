#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	ll n, k;
	cin >> n >> k;
	vector<int>v(n);
	for (int i = 0; i < n; ++i) 
		cin >> v[i];
	ll l = 0, r = 2e9;
	ll ans = 0;
	while (l <= r) {
		ll mid = (l + r)/2;
		ll tmp = 0;
		for (int i = 0; i < n; ++i) {
			if (v[i] >= mid) continue;
			tmp += (mid - v[i]);
		}
		if (tmp > k) {
			r = mid - 1;
		}
		else {
			ans = mid;
			l = mid + 1;
		}
	}
	cout << ans << endl;
	return 0;
}
