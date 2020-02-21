//2168 타일 위의 대각선
//20200221

#include<bits/stdc++.h>
using namespace std;

int gcd(int a, int b){
	if(b == 0) return a;
	return gcd(b, a%b);
}

int main(){
	int n, m;
	cin>>n>>m;
	cout<<m+n-gcd(n,m);
	return 0;
}
