#include <stdio.h>

int main(void)
{
	int i, j, k,l;
	scanf("%d", &i);
	for (j = 1; j <= i; j++)
	{
		for (k = i; k>= j; k--)
			printf("*");
		printf("\n");
	}
	return 0;
}
