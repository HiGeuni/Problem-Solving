#include<algorithm>
#include<vector>
#include<cstdio>
using namespace std;

int main(){
    int n, m, ans = 0;
    scanf("%d%d", &n, &m);
    vector<vector<int>>v(n+1, vector<int>(m+1, 0));
    vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
    for(int i=1;i<=n; ++i){
        for(int j=1;j<=m; ++j){
            scanf("%1d", &v[i][j]);
        }
    }
    for(int i=1; i<=n; ++i){
        for(int j=1;j<=m; ++j){
            if(v[i][j] == 1){
                dp[i][j] = min(min(dp[i-1][j], dp[i-1][j-1]), dp[i][j-1]) + 1;
                ans = max(dp[i][j], ans);
            }
        }
    }
    printf("%d", ans*ans);
    return 0;
}