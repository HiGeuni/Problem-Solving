#include<stdio.h>

int main() {
	long long max = -1000001, min = 1000001;
	long long T, num;
	scanf("%lld", &T);
	if (T == 1) {
		scanf("%lld", &num);
		printf("%lld %lld\n", num, num);
		return 0;
	}
	else {
		for (int i = 0; i < T; i++) {
			scanf("%lld", &num);
			if (num < min) {
				min = num;
			}
			if (num > max) {
				max = num;
			}
		}
	}
	printf("%lld %lld\n", min, max);
	return 0;
}
