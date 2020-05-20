//15979 스승님 찾기

#include <iostream>
using namespace std;

int gcd(int a, int b){
	if(a==0 || b==0) return a+b;
	if(b%a==0)
		return a;
	else if(a>b)
		return gcd(a%b, b);
	else
		return gcd(b%a,a);
}

int main() {
	int n, m;
	cin>>n>>m;
	if(n<0) n *=-1;
	if(m<0) m *=-1;
	if(n==0 && m==0) cout<<0<<endl;
	else{
		if(gcd(n,m) != 1) cout<<2<<endl;
		else cout<<1<<endl;
	}
	return 0;
}
