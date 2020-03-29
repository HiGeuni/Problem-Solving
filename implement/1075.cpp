#include<iostream>
#include<cstdio>
#include<vector>
#include<utility>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<tuple>
#include<algorithm>
using namespace std;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n,f;
	scanf("%d%d", &n, &f);
	n/=100;n*=100;
	for(;;n++){
		if(n%f==0) break;
	}
	printf("%02d", n%100);
	return 0;
}
