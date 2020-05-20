#include<stdio.h>

int main() {
	int ch[31] = { 0 }, cnt, tmp;
	for (int i = 0; i < 28; i++) {
		scanf("%d", &tmp);
		ch[tmp] = 1;
	}
	for (int i = 1; i <= 30; i++) {
		if (ch[i] == 0)
			printf("%d\n", i);
	}

	return 0;
}
