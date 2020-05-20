#include<stdio.h>

int main() {
	int a, b, c, cnt = 1, me;
	scanf("%d", &a);
	b = a / 10; c = a % 10;
	me = ((b + c) % 10) + c * 10;
	while (a!=me)
	{
		b = me / 10; c = me % 10;
		me = ((b + c) % 10) + c * 10;
		cnt++;
	}
	printf("%d", cnt);
	return 0;
}
