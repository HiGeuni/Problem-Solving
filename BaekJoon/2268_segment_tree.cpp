#include<cstdio>
#include<vector>
using namespace std;
typedef long long ll;

vector<ll> num(1000001, 0);
vector<ll> tree(4000001, 0);

ll query(ll left, ll right, ll node, ll queryLeft, ll queryRight) {
    if (right < queryLeft || left > queryRight) return 0; //범위 밖 -> 구할 수 없는 경우
    else if (left >= queryLeft && right <= queryRight) { //범위 안 -> 판단 가능
        return tree[node];
    }
    else{ //범위에 걸쳐있음 -> 판단 불가
        ll mid = (left + right) / 2;
        return query(left, mid, node * 2, queryLeft, queryRight) + query(mid + 1, right, node * 2 + 1, queryLeft, queryRight);
    }
}

void update(ll left, ll right, ll node, ll target, ll diff) {
    if(!(left <= target && target <= right)) return;
    //node가 범위 안 -> 업데이트
    tree[node] += diff;
    if (left != right) { //리프노드가 아닌 경우 자식 업데이트
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

        if (a == 1) { //b번째 수를 c로 바꾼다
            ll diff = c - num[b];
            num[b] = c;
            update(1, N, 1, b, diff);
        }
        else if (a == 0) { //b번째 수부터 c번째 수까지의 합 출력
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