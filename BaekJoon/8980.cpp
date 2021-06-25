#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
typedef pair<int,int> pii;
typedef tuple<int,int,int> tpiii;

bool compare(tpiii a, tpiii b){
    return get<1>(a) < get<1>(b);
}

int main(){
    int n, c, m, ta, tb, tc;
    int ans = 0;
    scanf("%d%d%d", &n, &c, &m);
    vector<int>truck(n+1, c);
    vector<tpiii> v(m);
    for(int i=0;i<m; ++i){
        scanf("%d%d%d", &ta, &tb, &tc);
        v[i] = make_tuple(ta, tb, tc);
    }
    sort(v.begin(), v.end(), compare);
    for(int i=0;i<m; ++i){
        int temp = c+1;
        int st = get<0>(v[i]);
        int ed = get<1>(v[i]);
        int cp = get<2>(v[i]);
        for(int j=st; j<ed; ++j){
            if(truck[j] < temp){
                temp = truck[j];
            }
        }
        int tmp = min(temp, cp);
        ans += tmp;
        for(int j=st; j<ed; ++j){
            truck[j] -= tmp;
        }
    }
    printf("%d", ans);
    return 0;
}