#include<cstdio>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	vector<int>v(N+1);
	unordered_map<int, int>m;
	int cnt = 0;
	int M = 0;
	for (int i = 0; i < N; ++i) {
		scanf("%d", &v[i]);
		M += v[i];
	}
	for (int i = 0; i < (1 << N); ++i) {
		int tmp = 0;
		for (int j = 0; j < N; ++j) {
			if ( i & 1 << j) {
				tmp += v[j];
			}
		}
		if (m.find(tmp) != m.end()) {
			continue;
		}
		else{
			cnt += 1;
			m[tmp] = 1;
		}
	}
	printf("%d", M - cnt + 1);
	return 0;
}
