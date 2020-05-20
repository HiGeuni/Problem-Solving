#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>seq;
int d[1234];
int T;

int LIS(int start) {
	if (start >= T)
		return 0;
	if (d[start] != 0) return d[start];
	d[start] = 1;
	for (int i = start + 1; i < T; i++) {
		if (seq[start] > seq[i]) {
			d[start] = max(d[start], LIS(i) + 1);
		}
	}
	return d[start];
}

int main() {
	int tmp;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &tmp);
		seq.push_back(tmp);
	}
	int ans = 0;
	for (int i = 0; i < T; ++i)
		ans = max(ans, LIS(i));
	printf("%d", ans);
}
