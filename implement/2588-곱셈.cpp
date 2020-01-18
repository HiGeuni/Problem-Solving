
#include<cstdio>

int main(){
	int a, b, tmp;
	scanf("%d%d", &a, &b);
	tmp = b;
	for(int i=0; i<3; i++){
		printf("%d\n", a*(b%10));
		b/=10;
	}
	printf("%d", a*tmp);
	return 0;
}

