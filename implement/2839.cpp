#include<stdio.h>

int main(void)
{
	int N, cnt=0;
	scanf("%d", &N);
	while (N!=0)
	{
		switch (N) {
		case 3: cnt += 1; printf("%d", cnt); return 0;
		case 6: cnt += 2; printf("%d", cnt); return 0;
		case 9: cnt += 3; printf("%d", cnt); return 0;
		case 12: cnt += 4; printf("%d", cnt); return 0;
		case 1: case 2: case 4: printf("-1"); return 0;
		}
		N = N - 5;
		cnt++;
	}
	printf("%d", cnt);
	return 0;
}
