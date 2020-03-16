#include<cstdio>
int main()
{
	int a, b, n, i, j, temp;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d%d", &a, &b);
		temp = a;
		for (j = 0; j < b - 1; j++)
		{
			a = temp * a % 10;
		}
		if (a == 0)
		{
			printf("10\n");
			continue;
		}
		printf("%d\n", a);
	}

	return 0;
}
