#include<iostream>
#define MOD 10007
using namespace std;
long long d[1010][11];
int main() {
	long long N, sum = 1;
	cin >> N;
	for (int i = 0; i <= 9; i++) {
		d[0][i] = 1;
	}
	for (int i = 0; i <= N; i++) {
		d[i][0] = 1;
	}
	if (N == 1) sum = 10;
	for (int i = 1; i < N; i++) {
		sum = 1;
		for (int j = 1; j < 10; j++) {
			d[i][j] = (d[i - 1][j] + d[i][j - 1])%MOD;
			sum += d[i][j];
			sum %= MOD;
		}
	}
	cout << sum << endl;
	return 0;
}
