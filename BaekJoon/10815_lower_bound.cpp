#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    vector<int>v(n);
    for(auto & x : v) cin>>x;
    sort(v.begin(), v.end());
    int m, tmp;
    cin>>m;
    for(int i=0;i<m; ++i){
        cin>>tmp;
        auto it = lower_bound(v.begin(), v.end(), tmp);
        if( *it == tmp) cout<<1<<' ';
        else cout<<0<<' ';
    }
    return 0;
}
