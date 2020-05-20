#include<stdio.h>
int main() {
	long long a, b, c;
	long long n, T,TC;
	scanf("%lld", &TC);
	for (int i = 0; i < TC; i++) {
		a = 1, b = 2, c = 4;
		scanf("%lld", &T);
		if (T == 1) {
			printf("1\n");
		} else if (T == 2) {
			printf("2\n");
		} else if (T == 3) {
			printf("4\n");
		}
		else {
			for (int j = 0; j < T - 3; j++) {
				n = a + b + c;
				a = b, b = c, c = n;
			}
			printf("%lld\n", n);
		}
	}
	return 0;
}
