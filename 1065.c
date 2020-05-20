#include<stdio.h>

int main() {
	int N, cnt = 0,a,b,c;
	scanf("%d",&N);
	for (int i = 1; i <= N; i++)
	{
		if (i == 1000)
			break;
		if (i >= 1 && i < 100)
			cnt++;
		else {
			a = i % 10;
			b = (i / 10) % 10;
			c = (i / 100) % 10;
			if ((a - b) == (b - c)) {
				cnt++;
			}
		}
	}
	printf("%d", cnt);
	return 0;
}
