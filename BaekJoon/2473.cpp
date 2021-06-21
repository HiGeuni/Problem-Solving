//
// Created by 김효근 on 2021/06/21.
//
#include<cstdio>
#include<vector>
#include<algorithm>
typedef long long ll;
using namespace std;

int main(){
    ll n;
    ll tmp, temp;
    ll ans = 4e9;
    scanf("%lld", &n);
    vector<ll>v(n);
    vector<ll>tmpV(3);
    for(int i=0;i<n; ++i)
        scanf("%lld", &v[i]);
    sort(v.begin(), v.end());
    for(int i=0;i<n-2; ++i){
        tmp = v[i];
        int l = i+1;
        int r = n-1;
        while(l<r){
            temp = tmp + v[l] + v[r];
            if(ans > abs(temp)){
                ans = abs(temp);
                tmpV[0] = v[i];
                tmpV[1] = v[l];
                tmpV[2] = v[r];
            }
            if(temp < 0) l++;
            if(temp > 0) r--;
            if(temp == 0) break;
        }
    }
    for(auto x : tmpV){
        printf("%lld ", x);
    }
    return 0;
}
