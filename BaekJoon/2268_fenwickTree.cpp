#include<cstdio>
#include<vector>
using namespace std;
typedef long long ll;
vector<ll> Tree(1000001, 0);

void Update(int Idx, ll Value){
    while(Idx < Tree.size()){
        Tree[Idx]+=Value;
        Idx = Idx + (Idx & - Idx);
    }
}

ll getSum(int Idx){
    ll Res =0;
    while(Idx > 0){
        Res += Tree[Idx];
        Idx = Idx - (Idx & -Idx);
    }
    return Res;
}

int main(){
    int N, M;
    int a, b, c;
    scanf("%d%d", &N, &M);
    for(int i=0; i<M; ++i){
        scanf("%d%d%d", &a, &b,&c);
        if(a == 0){
            if(b > c){
                b ^= c;
                c ^= b;
                b ^= c;
            }
            printf("%lld\n", getSum(c) - getSum(b-1));
        }else{
            ll diff = c - getSum(b) + getSum(b - 1);
            Update(b, diff);
        }
    }
    return 0;
}