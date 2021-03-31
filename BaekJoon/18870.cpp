#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie();
    ios_base::sync_with_stdio();
    int n;
    cin>>n;
    vector<int>v(n);
    vector<int>v2(n);
    for(int i=0;i<n; ++i){
        cin>>v[i];
        v2[i] = v[i];
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for(auto& x : v2)
        cout<<lower_bound(v.begin(), v.end(), x) - v.begin() <<" ";
    return 0;
}