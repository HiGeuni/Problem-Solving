#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;

ll d[100][100];
ll comb(int n, int r) {
	if (d[n][r] != 0) return d[n][r];
	if (n == r) { return d[n][r] = 1; }
	if (r == 1) {
		return d[n][r] = n;
	}
	if (n == 1) {
		return d[n][r] = 1;
	}
	return d[n][r] = comb(n - 1, r) + comb(n - 1, r - 1);
}

int main() {
	int n, r;
	cin >> n >> r;
	if (r == 0) {
		cout << 1;
		return 0;
	}
	cout << comb(n, r);
	return 0;
}
