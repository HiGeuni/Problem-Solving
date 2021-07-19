#include<iostream>
#include<vector>
using namespace std;

int main(){
    int N, K;
    cin>>N>>K;
    vector<vector<int>>v(N, vector<int>(4));
    for(int i=0;i<N; ++i)
        cin>>v[i][0]>>v[i][1]>>v[i][2]>>v[i][3];
    vector<vector<int>>dp(N, vector<int>(K+1, -1));
    dp[0][v[0][0]] = v[0][1];
    dp[0][v[0][2]] = max(v[0][3],dp[0][v[0][2]]);
    for(int i=1; i<N; ++i){
        for(int j=0;j<K+1; ++j){
            if(dp[i-1][j] == -1) continue;
            if(v[i][0] + j <= K){
                dp[i][v[i][0] + j] = max(dp[i][v[i][0] + j], dp[i-1][j] + v[i][1]);
            }
            if(v[i][2] + j <= K){
                dp[i][v[i][2] + j] = max(dp[i][v[i][2] + j], dp[i-1][j] + v[i][3]);
            }
        }
    }
    int ans = -1;
    for(int i=0;i<K+1; ++i){
        ans = max(ans, dp[N-1][i]);
    }
    cout<<ans;
    return 0;
}