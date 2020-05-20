#include<stdio.h>
int main() {
	int N, K, a[101], sum =0;
	scanf("%d%d", &N, &K);
	for (int i = 0; i < K; i++) {
		scanf("%d", &a[i]);
		if (a[i] % 2 == 0) {
			a[i] = a[i] / 2;
		}
		else {
			a[i] = a[i] / 2 + 1;
		}
		sum += a[i];
	}
	if (sum >= N) {
		printf("YES\n");
	}
	else printf("NO\n");
	return 0;
}
