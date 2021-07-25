#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<cmath>
using namespace std;

int main(){
    int Tc;
    cin>>Tc;
    for(int tc =0;tc<Tc; ++tc){
        int N;
        cin>>N;
        vector<vector<int>>v(2, vector<int>(N));
        vector<vector<int>>dp(2, vector<int>(N));
        for(int i=0;i<2; ++i){
            for(int j=0;j<N; ++j){
                cin>>v[i][j];
            }
        }
        dp[0][0] = v[0][0];
        dp[1][0] = v[1][0];
        dp[0][1] = v[0][1] + v[1][0];
        dp[1][1] = v[1][1] + v[0][0];
        for(int i=2; i<N; ++i){
            dp[0][i] = v[0][i] + max(dp[1][i-1],dp[1][i-2]);
            dp[1][i] = v[1][i] + max(dp[0][i-1],dp[0][i-2]);
        }
        cout<<max(dp[0][N-1], dp[1][N-1])<<'\n';
    }
    return 0;
}