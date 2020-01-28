#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin>>n;
    vector<int>v(n);
    for(int i=0; i<n; ++i)
        cin>>v[i];
    sort(v.begin(), v.end());
    for(int i=0; i<n; ++i)
        cout<<v[i]<<'\n';
    return 0;
}
