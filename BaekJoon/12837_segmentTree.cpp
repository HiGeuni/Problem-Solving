#include<cstdio>
#include<vector>
using namespace std;
typedef long long ll;

vector<ll> num(1000001, 0);
vector<ll> tree(4000001, 0);

ll query(ll left, ll right, ll node, ll queryLeft, ll queryRight) {
    if (right < queryLeft || left > queryRight) return 0;
    else if (left >= queryLeft && right <= queryRight) {
        return tree[node];
    }
    else{
        ll mid = (left + right) / 2;
        return query(left, mid, node * 2, queryLeft, queryRight) + query(mid + 1, right, node * 2 + 1, queryLeft, queryRight);
    }
}

void update(ll left, ll right, ll node, ll target, ll diff) {
    if(!(left <= target && target <= right)) return;
    tree[node] += diff;
    if (left != right) {
        ll mid = (left + right) / 2;
        update(left, mid, node * 2, target, diff);
        update(mid+1, right, node * 2+1, target, diff);
    }
}

int main() {
    ll N, M;
    ll n, a, b, c;
    scanf("%lld%lld", &N, &M);

    for (int i = 0; i < M; i++) {
        scanf("%lld%lld%lld", &a, &b, &c);

        if (a == 1) {
            num[b] = c+num[b];
            update(1, N, 1, b, c);
        }
        else if (a == 2) {
            if(b>c){
                b ^= c;
                c ^= b;
                b ^= c;
            }
            printf("%lld\n", query(1, N, 1, b, c));
        }
    }

    return 0;
}
