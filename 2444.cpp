#20200424
#2444 별찍기 -7

#include<cstdio>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; ++i){
		for(int j=n-i; j>0; --j)
			printf(" ");
		for(int j=0; j<2*i-1; ++j)
			printf("*");
		printf("\n");
	}
	for(int i=1; i<n; ++i){
		for(int j=0; j<i; ++j)
			printf(" ");
		for(int j=2*(n-i)-1; j>0; --j)
			printf("*");
		printf("\n");
	}
	return 0;
}
