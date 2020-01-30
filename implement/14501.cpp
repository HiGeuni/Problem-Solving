#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, res = -1;
	int arr[16][2]; //0 : time 1 : pay
	int dp[16];
	memset(dp, 0, sizeof(dp));
	cin>>n;
	for(int i=0; i<n; ++i)
		for(int j=0; j<2; ++j)
			cin>>arr[i][j];

	for(int i=0; i<=n; ++i){
		for(int j=0; j<i; ++j){
			dp[i] = max(dp[i], dp[j]);
			if(j+arr[j][0] == i)
				dp[i] = max(dp[i], dp[j] + arr[j][1]);
		}
		res = max(res, dp[i]);
	}
	cout<<res;
	return 0;
}
