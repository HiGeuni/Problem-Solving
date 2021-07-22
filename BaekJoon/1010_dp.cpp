#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int tc;
    cin>>tc;
    for(int t=0;t<tc; ++t){
        int N, M;
        cin>>N>>M;
        vector<vector<int>>dp(N+1, vector<int>(M+1, 0));
        for(int i=1;i<M+1; ++i){
            dp[1][i] = i;
        }
        for(int i=2;i<N+1; ++i){
            for(int j=i;j<M+1; ++j){
                if(i==j){
                    dp[i][j] = 1;
                    continue;
                }
                for(int k=j-1; k>0; --k){
                    dp[i][j] += dp[i-1][k];
                }
            }
        }
        cout<<dp[N][M]<<endl;
    }
}

