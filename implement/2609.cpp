#include<stdio.h>

int GCM(int x, int y) {//최대 공약수
	for (int i = 1; ; i++) {
		if (i%x == 0 && i%y == 0) {
			return i;
		}
	}
}

int LCM(int x, int y) {
	if (x > y) {
		for (int i = x; i>0; i--) {
			if (x%i == 0 && y%i == 0) {
				return i;
			}
		}
	}
	else {
		for (int i = y; i>0; i--) {
			if (x%i == 0 && y%i == 0) {
				return i;
			}
		}
	}

}

int main() {
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d\n%d\n", LCM(a, b), GCM(a, b));
	return 0;
}
