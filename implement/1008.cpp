#include <stdio.h>

int main(void)
{
	int b, a;
	scanf("%d%d", &a, &b);
	printf("%.9Lf", (long double)a / b);
	return 0;
}
