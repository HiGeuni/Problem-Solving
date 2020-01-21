#include<bits/stdc++.h>
using namespace std;
const int mod = 9901;
int dp[3][100001];

int main(){
	int N;
	cin>>N;
	for(int i=0; i<3; i++)
		dp[i][0] = 1;
	for(int i=0; i<N-1;i++){
		dp[0][i+1] += (dp[1][i] + dp[2][i])%mod;
		dp[1][i+1] += (dp[0][i] + dp[2][i])%mod;
		dp[2][i+1] += (dp[0][i] + dp[1][i] + dp[2][i])%mod;
	}
	cout<<(dp[0][N-1]+dp[1][N-1]+dp[2][N-1])%mod;
	return 0;
}
