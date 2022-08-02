#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

typedef struct dInfo{
    int src;
    int dst;
    int interval;
};

int N, K, D;
vector<dInfo>rules;

bool decision(int m){
    ll dotori = 0;
    for(int i=0; i<K; ++i){
        if(min(rules[i].dst, m) < rules[i].src) continue;
        dotori += ((min(rules[i].dst, m) - rules[i].src)/rules[i].interval + 1);
    }
    return dotori >= D;
}

int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>N>>K>>D;
    rules.resize(K);
    for(int i=0; i<K; ++i){
        cin>>rules[i].src>>rules[i].dst>>rules[i].interval;
    }
    int l = 0, r = N+1;
    while(l<=r){
        int mid = (l+r)/2;
        if(decision(mid)){
            r = mid - 1;
        }else{
            l = mid + 1;
        }
    }
    cout<<l<<endl;
    return 0;
}
