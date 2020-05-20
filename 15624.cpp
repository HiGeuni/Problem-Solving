#include<iostream>
using namespace std;
typedef long long ll;
#define mod 10007
ll memo[1001000];
ll fibo(int n){
	if (n <= 1)
		return n;
	else if (memo[n] != 0)return memo[n];
	else return memo[n] = (fibo(n - 1) + fibo(n - 2))%1000000007;
}

int main(){
	int n;
	cin >> n;
	cout << fibo(n);
	return 0;
}
