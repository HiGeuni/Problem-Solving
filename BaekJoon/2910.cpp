#include<bits/stdc++.h>
using namespace std;

typedef pair<int,string>pis;
map<string, int>order;

bool compare(pis a, pis b){
    if(a.first == b.first) return order[a.second] < order[b.second];
    return a.first > b.first;
}

int main(){
    int n, c;
    map<string, int>m;
    cin>>n>>c;
    string tmp;
    int t;
    for(int i=0;i<n; ++i){
        cin>>tmp;
        if(!m[tmp]) {
            order[tmp] = i;
        }
        m[tmp] += 1;
    }
    vector<pis>v;
    for(auto it = m.begin(); it!=m.end(); ++it){
        v.push_back({it->second, it->first});
    }
    sort(v.begin(), v.end(), compare);
    for(int i=0;i<v.size(); ++i){
        for(int j=0;j<v[i].first; ++j){
            cout<<v[i].second<<" ";
        }
    }
    return 0;
}