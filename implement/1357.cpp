#include <cstdio>
int rev(int n)
{
	int res = 0;
	while (n) {
		res *= 10;
		res += n % 10;
		n /= 10;
	}
	return res;
}
int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d",rev((rev(a)+rev(b))));
	return 0;
}
