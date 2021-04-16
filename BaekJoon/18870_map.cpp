#include<bits/stdc++.h>
using namespace std;

int main(){
    unordered_map<int, int> um;
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n; ++i)
        cin>>v[i];
    vector<int>tmp;
    tmp = v;
    sort(v.begin(), v.end());
    int idx = 0;
    for(int i=0;i<n; ++i){
        if(um.find(v[i]) == um.end()){
            um[v[i]] = idx++;
        }
        else continue;
    }
    for(auto x : tmp)
        cout<<um[x]<<" ";
    return 0;
}