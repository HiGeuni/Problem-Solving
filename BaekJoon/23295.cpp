#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    ll N, T, tmp, a, b, max_time = 0;
    cin>>N>>T;
    vector<ll>v(100001, 0);

    //입력 & imos
    for(int i=0; i<N; ++i){
        cin>>tmp;
        for(int j=0; j<tmp; ++j){
            cin>>a>>b;
            v[a]++;
            v[b]--;
            max_time = max(max_time, max(a, b));
        }
    }
    
    ll ansIdx = 0, ans = v[0];
    tmp = v[0];
    //누적 합
    for(int i=1; i<max_time + 1; ++i){
        v[i] += v[i-1];
        if(i < T){
            tmp += v[i];
        }else{
            tmp -= v[i-T];
            tmp += v[i];
        }
        if(tmp > ans){
            ansIdx = i - T + 1;
            ans = tmp;
        }
    }
    cout<<ansIdx<< " " <<ansIdx + T;
    
    return 0;
}
