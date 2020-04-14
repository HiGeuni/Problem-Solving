#include<stdio.h>

int main(void)
{
	int x, i, j, arr[10000];
	scanf("%d%d", &x,&i);

	for (j = 0; j < x; j++) {
		scanf("%d", &arr[j]);
	}
	for (j = 0; j < x; j++)
	{
		if (arr[j] < i)
			printf("%d ", arr[j]);
	}
	return 0; 
}
