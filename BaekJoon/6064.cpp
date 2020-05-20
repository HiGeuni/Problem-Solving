//6064 카잉 달력
//20180702

#include<cstdio>
int main(void) {
	int N, M, x, y, k=0, T;
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d%d%d%d", &M, &N, &x, &y);
		k = x;
		while (1)
		{
			if ((k - x) % M == 0 && (k - y) % N == 0) {
				break;
			}
			if (k > N*M) {
				k = -1; break;
			}
			k += M;
		}
		printf("%d\n", k);
	}
	return 0;
}
