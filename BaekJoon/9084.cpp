//9084 동전
//20200220
 
#include<bits/stdc++.h>
using namespace std;

int coin[20];
int main(){
	cin.tie();
	ios_base::sync_with_stdio();
    int tc;
    cin>>tc;
    for(int k=0; k<tc; ++k){
        int num_coin;
        cin>>num_coin;
        for (int i = 0; i < num_coin; ++i)
            cin>>coin[i];
        int cost;
        cin>>cost;
    	vector<int>dp(cost+1,0);
    	dp[0] =1;
        for (int i = 0; i < num_coin; ++i){
            for (int j = coin[i]; j <= cost; ++j)
                dp[j] += dp[j - coin[i]];
        }
        cout<<dp[cost]<<endl;
    }
}
