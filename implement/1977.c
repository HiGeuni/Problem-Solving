#include<stdio.h>
int square(int a);

int main() {
	int num1, num2, sum=0, min=100000;
	scanf("%d%d", &num1, &num2);
	for (int i = num1; i <= num2; i++) {
		if (square(i) == 1) {
			sum += i;
			if (i < min) min = i;
		}
	}
	if (sum == 0) {
		printf("-1\n");
	}
	else {
		printf("%d\n%d\n", sum, min);
	}
	return 0;
}

int square(int a) {
	for (int i = 1; i*i <= a; i++) {
		if (i*i == a) {
			return 1;
		}
	}
	return 0;
}
