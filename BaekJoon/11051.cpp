#include<bits/stdc++.h>
using namespace std;

int dp[1010][1010];

int recursive(int n, int k){
    if(n == k || k == 0) return dp[n][k] = 1;
    if(dp[n][k]) return dp[n][k];
    else
        return dp[n][k] = (recursive(n-1, k-1) + recursive(n-1, k)) % 10007;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int N, K;
    cin>>N>>K;
    int ans = recursive(N, K);
    cout<<ans<<'\n';
    return 0;
}
