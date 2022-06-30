#include<bits/stdc++.h>
using namespace std;

vector<bool> eratos(int n) {
	vector<bool>prime(n+1, true);
	prime[1] = false;
	for (int i = 2; i < sqrt(n); ++i) {
		if (prime[i]) {
			for (int j = i*i; j <= n; j += i) {
				prime[j] = false;
			}
		}
	}
	return prime;
}

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, m,edx = 2003;
	vector<bool>e = eratos(100000);
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 1; j <= m; ++j) {
			cout << edx * j <<" ";
		}
		cout << '\n';
		edx += 1;
		while (!e[edx])edx += 1;
	}
	return 0;
}
