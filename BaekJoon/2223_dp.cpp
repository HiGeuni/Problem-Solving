#include<bits/stdc++.h>
using namespace std;
#define MOD 1000000000

int main(){
    //dp[i][j] : i개를 이용해 j를 만들 수 있는 경우의 수
    vector<vector<int>>dp(201, vector<int>(201, 0));
    int N, M;
    cin>>N>>M;
    for(int i=0;i<201; ++i) {
        dp[0][i] = 1;
        dp[i][0] = 1;
    }
    for(int i=1;i<M; ++i){
        for(int j=1; j<N+1; ++j){
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
        }
    }
    cout<<dp[M-1][N];
    return 0;
}