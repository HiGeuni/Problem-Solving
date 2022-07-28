#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int ccw(pii a, pii b, pii c) {
	return a.first * b.second + b.first * c.second + a.second * c.first - (a.second * b.first + b.second * c.first + a.first * c.second);
}

int main() {
	pii a[3];
	for (int i = 0; i < 3; ++i)
		cin >> a[i].first >> a[i].second;
	int t = ccw(a[0], a[1], a[2]);
	if (t == 0) cout << 0 << '\n';
	else cout << ((t < 0) ? -1 : 1) << '\n';
	return 0;
}
