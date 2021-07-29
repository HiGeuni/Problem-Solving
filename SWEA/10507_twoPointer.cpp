#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int Tc;
    scanf("%d", &Tc);
    for(int tc =0; tc<Tc; ++tc){
        int N, M, max_=0;
        scanf("%d%d", &N, &M);
        vector<int>v(N);
        for(int i=0;i<N; ++i){
            scanf("%d", &v[i]);
            max_ = max(max_, v[i]);
        }
        vector<bool>visited(max_+M+1, false);
        for(int i=0;i<N; ++i){
            visited[v[i]] = true;
        }
        max_ = max_ + M + 1;
        int l = 0;
        int r = 0;
        int ans = 0, cnt = 0;
        while(r <= max_){
            if(visited[r]){
                r += 1;
                cnt += 1;
                ans = max(cnt, ans);
            }else{
                if(M == 0){
                    ans = max(cnt, ans);
                    if(!visited[l]) M+=1;
                    l += 1;
                    cnt -= 1;
                }else{
                    ans = max(cnt, ans);
                    cnt += 1;
                    r += 1;
                    M -= 1;
                }
            }
        }
        printf("#%d %d\n",tc+1, ans);
    }
    return 0;
}