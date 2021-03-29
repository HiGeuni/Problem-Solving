#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie();
    int tc, N, L, tmp, cnt;
    double ans;
    cin>>tc;
    for(int i=0;i<tc; ++i){
        cin>>N>>L;
        vector<int>v(N);
        for(auto &x:v) cin>>x;
        ans = 2000000000.0f;
        for(int j=0;j<=N-L; ++j){
            tmp = 0;
            cnt = 0;
            for(int k=j;k<N; ++k){
                tmp += v[k];
                cnt ++;
                if(cnt>=L)
                    ans = min(ans, (double)tmp / (double)cnt);
            }
        }
        printf("%.8lf\n", ans);
    }
    return 0;
}