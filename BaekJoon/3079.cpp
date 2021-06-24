#include<cstdio>
#include<vector>
using namespace std;
typedef long long ll;

int main(){
    ll n,m;
    scanf("%lld%lld", &n, &m);
    vector<ll>v(n);
    for(ll i=0;i<n; ++i)
        scanf("%lld", &v[i]);
    sort(v.begin(), v.end());
    ll ans=0;
    ll l = 1;
    ll r = v.back()*m;
    while(l<=r){
        ll mid = (l+r)/2;
        ll tmp = 0;

        for(int i=0;i<n; ++i)
            tmp += (mid/v[i]);

        if(tmp < m){
            l = mid+1;
        }else{
            ans = mid;
            r = mid-1;
        }
    }
    printf("%lld", ans);
    return 0;
}