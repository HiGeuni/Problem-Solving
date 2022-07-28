#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int>dp(n+1, 0);
    dp[0] = 1;
    dp[2] = 3;
    for(int i=4; i<=n; i+=2){
        dp[i] = dp[i-2] * 3;
        for(int j=0; j <= i-4; j += 2){
            dp[i] += dp[j] * 2;
        }
    }
    cout<<dp[n]<<'\n';
    return 0;
}
