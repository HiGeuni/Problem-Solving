//11659 구간 합 구하기 4

#include<iostream>
#include<vector>

int main() {
	std::cin.tie(NULL);
	std::ios::sync_with_stdio(false);
	std::vector<int>v;
	std::vector<int>sum;
	v.reserve(100100);
	int N, M, tmp, ts=0;
	std::cin >> N >> M;
	for (int i = 0; i < N; i++) {
		std::cin >> tmp;
		v.push_back(tmp);
		ts += tmp;
		sum.push_back(ts);
	}
	int a, b;
	for (int i = 0; i < M; i++) {
		std::cin >> a >> b;
		std::cout << (a > 1 ? sum[b - 1] - sum[a - 2] : sum[b - 1]) << '\n';
	}
}
