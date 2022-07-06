#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, q;
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	cin >> q;
	int l = 0, r = v.size() - 1, cnt = 0;
	while (l < r) {
		cout << "L : " << l << " R : " << r <<" cnt : "<<cnt<< endl;
		int t = v[l] + v[r];
		if (t == q) {
			cnt++;
			l++;
			r--;
		}
		else if (t < q) {
			l++;
		}
		else {
			r--;
		}
	}
	cout << cnt << '\n';
	return 0;
}
