#include<cstdio>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;

int main(){
    int tc;
    scanf("%d", &tc);
    for(int Tc=1; Tc<=tc; ++Tc){
        int num;
        scanf("%d", &num);
        vector<int>ans;
        priority_queue<int>pq;
        for(int i=0; i<num; ++i){
            int cmd, n;
            scanf("%d", &cmd);
            if(cmd == 1){
                scanf("%d", &n);
                pq.push(n);
            }else{
                if(pq.empty()) ans.push_back(-1);
                else{
                    ans.push_back(pq.top());
                    pq.pop();
                }
            }
        }
        printf("#%d ", Tc);
        for(int x : ans) printf("%d ", x);
        printf("\n");
    }
    return 0;
}