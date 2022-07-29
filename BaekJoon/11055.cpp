#include<bits/stdc++.h>
using namespace std;

vector<int>v, dp;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int n, ans = 0;
    cin>>n;
    v.resize(n);
    dp.resize(n);
    for(int i=0; i<n; ++i){
        cin>>v[i];
        dp[i] = v[i];
        for(int j=0; j<i; ++j){
            if(v[i] > v[j] && dp[i] < dp[j] + v[i]){
                dp[i] = dp[j] + v[i];
            }
        }
        ans = max(ans, dp[i]);
    }
    cout<<ans<<'\n';
    
    return 0;
}
