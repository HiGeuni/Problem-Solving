#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    unordered_map<string, string>um;
    int n,m;
    string tmp;
    cin>>n>>m;
    for(int i=1;i<=n; ++i){
        cin>>tmp;
        um[tmp] = to_string(i);
        um[to_string(i)] = tmp;
    }
    for(int i=0;i<m; ++i){
        cin>>tmp;
        cout<<um[tmp]<<'\n';
    }
    retrun 0;
}
