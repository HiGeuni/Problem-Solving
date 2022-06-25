#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N, M, tmp, sum_=0;
	cin >> N;
	vector<int>dp(40001, 0);
	vector<int>prev(40001, 0);
	prev[0] = 1;
	for (int i = 0; i < N; ++i) {
		cin >> tmp;
		sum_ += tmp;
		for (int j = sum_; j >= 0; -- j) {
			if (prev[j] == 1) {
				if (j > tmp) {
					dp[j - tmp] = 1;
				}
				else {
					dp[tmp - j] = 1;
				}
				if (j + tmp <= 40000) {
					dp[j + tmp] = 1;
				}
			}
		}
		for (int j = 0; j <= sum_; ++j) {
			if(dp[j] != 0)
				prev[j] = dp[j];
			dp[j] = 0;
		}
	}
	cin >> M;
	for (int i = 0; i < M; ++i) {
		cin >> tmp;
		if (prev[tmp]) cout << "Y ";
		else cout << "N ";
	}
	return 0;
}
