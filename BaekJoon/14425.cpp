#include <bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<string, int> um;
    int n,m;
    cin>>n>>m;
    string tmp;
    for(int i=0;i<n; ++i){
        cin>>tmp;
        um[tmp] = 1;
    }
    int ans=0;
    for(int i=0;i<m; ++i){
        cin>>tmp;
        auto item = um.find(tmp);
        if(item != um.end()) ans++;
    }
    cout<<ans;
    return 0;
}
