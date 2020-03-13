//1003 피보나치 수

#include<cstdio>

int fibonacci(int n) {
	static int mem[40] = { 1, 1, }; 
	if (n <= 1) return mem[n];    
	else if (mem[n] > 0) return mem[n];
	return mem[n] = fibonacci(n - 1) + fibonacci(n - 2);
}
int main() {
	int n, N;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &N);
		if (N == 0) printf("1 0\n");
		else printf("%d %d\n", fibonacci(N-2), fibonacci(N-1));
	}
	return 0;
}
