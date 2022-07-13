#include<bits/stdc++.h>
using namespace std;

vector<int> rest;
int binary_search(int M, int L) {
    int l = 1, r = L - 1;

    while (l <= r) {
        int mid = (l + r) / 2;
        int cnt = 0;
        for (int i = 1; i < rest.size(); ++i) {
            int t = rest[i] - rest[i - 1];
            cnt += t / mid;
            if (t % mid == 0) cnt--;
        }
        if (cnt > M) l = mid + 1;
        else r = mid - 1;
    }

    return l;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    int N, M, L;
    cin >> N >> M >> L;

    rest.resize(N + 2);

    rest[0] = 0;
    for (int i = 1; i <= N; ++i) cin >> rest[i];
    rest[N + 1] = L;

    sort(rest.begin(), rest.end());

    cout << binary_search(M, L);

    return 0;
}
