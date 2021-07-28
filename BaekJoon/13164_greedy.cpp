#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, K;
    scanf("%d%d", &N, &K);
    vector<int>v(N);
    vector<int>tmp(N, 2e9);
    scanf("%d", &v[0]);
    for(int i=1; i<N; ++i){
        scanf("%d", &v[i]);
        tmp[i] = v[i] - v[i-1];
    }
    sort(tmp.begin(), tmp.end());
    int ans =0;
    for(int i=0;i<N-K; ++i){
        ans += tmp[i];
    }
    printf("%d", ans);
    return 0;
}

