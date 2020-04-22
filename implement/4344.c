#include<stdio.h>

int main(void)
{
	int score[1001][1001];
	int C, N[1001], cnt, sum[1001] = { 0, };

	scanf("%d", &C);
	for (int i = 0; i < C; i++)
	{
		scanf("%d", &N[i]);
		for (int j = 0; j < N[i]; j++)
		{
			scanf("%d", &score[i][j]);
			sum[i] += score[i][j];
		}
	}
	for (int i = 0; i < C; i++)
	{
		cnt = 0;
		for (int j = 0; j < N[i]; j++)
		{
			if (score[i][j] > sum[i]/N[i])
			{
				cnt++;
			}
		}
		printf("%.3lf%%\n", (double) cnt/N[i]*100);
	}
	return 0;
}
