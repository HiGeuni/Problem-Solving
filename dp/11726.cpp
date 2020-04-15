#include<cstdio>

int main()
{
	long long tile[1001], n, i;
	tile[0] = 1;
	tile[1] = 2;
	scanf("%lld", &n);
	for (i = 2; i < n; i++) {
		tile[i] = (tile[i - 1] + tile[i - 2]) % 10007;
	}
	printf("%lld", tile[n - 1]);
    return 0;
} 
