#include <stdio.h>
int main() {
	int n, c=0;
	scanf("%d", &n);
	while (n/5!=0) {
		n /= 5;
		c += n;
	}
	printf("%d", c);
	return 0;
}
