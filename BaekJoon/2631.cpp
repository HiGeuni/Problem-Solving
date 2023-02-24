#include<cstdio>
#include<vector>
using namespace std;

int main() {
	int N, tmp, ans=1;
	scanf("%d", &N);
	vector<int>v;
	vector<int>dp(N + 1, 1);
	for (int i = 0; i < N; ++i) {
		scanf("%d", &tmp);
		v.push_back(tmp);
	}
	for (int i = 1; i < N; ++i) {
		for (int j = 0; j < i; ++j) {
			if (v[i] > v[j] && dp[j] + 1 > dp[i]) {
				dp[i] = dp[j] + 1;
				ans = max(ans, dp[i]);
			}
		}
	}
	printf("%d\n", N - ans);

	return 0;
}
