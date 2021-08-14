#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
typedef pair<int, int> pii;



int main() {
    int N, M;
    scanf("%d%d", &N, &M);
    vector<vector<pii>>v(N+1);
    vector<bool>visited;
    for (int i = 0; i < M; ++i) {
        int u, f, w;
        scanf("%d%d%d", &u, &f, &w);
        v[f].push_back({ u, w });
        v[u].push_back({ f, w });
    }
    int s, e;
    scanf("%d%d", &s, &e);
    int l = 0;
    int r = 1000000001;
    while (l <= r) {
        int mid = (l + r) / 2;
        deque<int>dq;
        dq.push_back(s);
        visited.clear();
        visited.resize(N + 1, false);
        visited[s] = true;
        bool flag = false;
        while (!dq.empty()) {
            int cur = dq.front();
            dq.pop_front();
            if (cur == e) {
                flag = true;
                break;
            }
            for (int i = 0; i < v[cur].size(); ++i) {
                int nextNode = v[cur][i].first;
                int nextCost = v[cur][i].second;
                if (!visited[nextNode] && mid <= nextCost) {
                    visited[nextNode] = true;
                    dq.push_back(nextNode);
                }
            }
        }
        if (flag) {
            l = mid+1;
        }
        else {
            r = mid-1;
        }
    }
    printf("%d", r);
    return 0;
}
