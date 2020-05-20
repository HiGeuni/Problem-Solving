#include<cstdio>
#include<vector>
using namespace std;

const int MaxN = 50;
int n,tmp, a[MaxN], b[MaxN];
int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &tmp);
		a[i] = tmp;
		for (int j = 0; j < i; j++){
			a[j]>a[i] ? b[j]++ : b[i]++;
		}
	}
	for (int i = 0; i < n; i++){
		printf("%d ", b[i]);
	}
}
