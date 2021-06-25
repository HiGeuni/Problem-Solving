#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef pair<int,int> pii;

int main(){
    int n,m;
    scanf("%d%d", &n, &m);
    vector<int>dp(n+1);
    vector<pii>coin(m);
    dp[0] = 1;
    for(int i=0;i<m; ++i)
        scanf("%d%d", &coin[i].first, &coin[i].second);
    sort(coin.begin(), coin.end());
    for(int i=0;i<m;++i){
        int cur = coin[i].first;
        for(int j=n; j>=0; --j){
            for(int k=1;k<=coin[i].second; ++k){
                if(j-k*cur >= 0) {
                    dp[j] += dp[j-k * cur];
                }
            }
        }
    }
    printf("%d", dp[n]);
    return 0;
}