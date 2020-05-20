#include<bits/stdc++.h>
using namespace std;

int dp[50];

int fibo(int n){
	if(dp[n]!=-1) return dp[n];
	return dp[n] = fibo(n-1) + fibo(n-2);
}

int main(){
	int n, tmp;
	cin>>n;
	memset(dp, -1, sizeof(dp));
	dp[0] = 0; dp[1] = 1;
	cout<< fibo(n-1) << " "<< fibo(n);
	return 0;
}
