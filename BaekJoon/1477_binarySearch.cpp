#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX 200001;

int main() {
    int N, M, L, tmp;
    scanf("%d%d%d", &N, &M, &L);
    vector<int>v;
    v.push_back(0);
    for (int i = 1; i <= N; ++i) {
        scanf("%d", &tmp);
        v.push_back(tmp);
    }
    v.push_back(L);
    sort(v.begin(), v.end());
    int l = 0;
    int r = L;
    int ans = 2e9;
    while (l <= r) {
        int mid = (l + r) / 2;
        int cnt = 0;
        for (int i = 1; i < N+2; ++i) {
            if ((v[i] - v[i - 1]) / mid > 0) {
                if((v[i] - v[i-1])  % mid == 0){
                    cnt += ((v[i] - v[i - 1]) / mid - 1);
                }
                else {
                    cnt += (v[i] - v[i - 1]) / mid;
                }
            }
        }
        if (cnt <= M) {
            ans = min(ans, mid);
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }
    printf("%d\n", ans);
    return 0;
}
