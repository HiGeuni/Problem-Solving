#include<bits/stdc++.h>
using namespace std;

int main(){
	int arr[5001], dp[5001][3];
	string str;
	cin>>str;
	memset(dp, 0, sizeof(dp));
	int sz = str.size();
	for(int i=0; i<sz; ++i)
		arr[i] = str[i] - '0';
	if((sz == 1 && arr[0] == 0) || arr[0] == 0){
		cout<<0;
		return 0;
	}
	dp[0][0] = 1; dp[0][1] = 0; dp[0][2] = 1;
	for(int i=1; i<sz; ++i){
		if(arr[i]>0){
			dp[i][0] = dp[i-1][2] % 1000000;
		}
		if(arr[i-1] * 10 + arr[i] <= 26 && arr[i-1]*10 + arr[i] >=10)
			dp[i][1] += dp[i-1][0]%1000000;
		dp[i][2] = (dp[i][0] + dp[i][1]) %1000000;
	}
	
	cout<<dp[sz-1][2];
	return 0;
}
