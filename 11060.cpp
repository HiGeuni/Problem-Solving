#20200424
#11060 

#include<iostream>
using namespace std;

int dp[1001];

int main(){
	int n, tmp;
	cin>>n;
	dp[1] = 1;
	for(int i=1; i<=n; ++i){
		cin>>tmp;
		int & num = dp[i];
		if(num == 0)
			continue;
		for(int j=1; j<=tmp ;++j ){
			if(i+j>1000)
				break;
			if(dp[i+j]>num+1 || dp[i+j] == 0)
				dp[i+j] = num+1;
		}
	}
	if(dp[n] == 0)
		cout<<-1;
	else
		cout<<dp[n]-1;
	return 0;
}
