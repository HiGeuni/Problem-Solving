#include<iostream>
#include<cstdio>
#include<unordered_map>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int Tc;
    scanf("%d", &Tc);
    char s[51];
    unordered_map<string, int>m1;
    for(int tc=1; tc<=Tc; ++tc){
        m1.clear();
        int N, M, ans = 0;
        scanf("%d%d", &N, &M);
        for(int i=0; i<N; ++i){
            scanf("%s", s);
            m1[s] = 1;
        }
        for(int j=0; j<M; ++j){
            scanf("%s", s);
            if(m1[s]) ans += 1;
        }
        printf("#%d %d\n", tc, ans);
    }
    return 0;
}