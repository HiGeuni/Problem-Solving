#include<cstdio>
#include<queue>
#include<algorithm>
#include<vector>
#include<utility>
#include<cstring>
using namespace std;


int main(){
    int tc;
    scanf("%d", &tc);
    for(int Tc=1; Tc<=tc; ++Tc){
        long long sum_ =0;
        priority_queue<int>maxPq;
        priority_queue<int, vector<int>, greater<int>>minPq;
        int init, N, n1, n2;
        scanf("%d%d", &N, &init);
        maxPq.push(init);
        for(int i=0; i<2*N; ++i) {
            scanf("%d", &n1);
            if(maxPq.size() == 0) maxPq.push(n1);
            else{
                if(maxPq.top() < n1){
                    minPq.push(n1);
                }else{
                    maxPq.push(n1);
                }
                if(maxPq.size() > minPq.size()){
                    while(maxPq.size() - minPq.size() > 1){
                        int t = maxPq.top();
                        maxPq.pop();
                        minPq.push(t);
                    }
                }else{
                    while(maxPq.size() < minPq.size()){
                        int t = minPq.top();
                        minPq.pop();
                        maxPq.push(t);
                    }
                }
            }
            if(i & 1){
                sum_ += maxPq.top();
                sum_ %= 20171109;
            }
        }
        printf("#%d %lld", Tc, sum_);
    }
    return 0;
}