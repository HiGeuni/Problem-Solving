#include<stdio.h>
int main(void) {
	int i, j, k, l;
	scanf("%d", &i);
	for (j = 1; j <= i; j++)
	{
		scanf("%d%d", &k, &l);
		printf("%d\n", k+l);
	}
	return 0;
}
