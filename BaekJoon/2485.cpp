#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    vector<int>tmp;
    for(int i=0; i<n; ++i) {
        cin >> v[i];
        if(i != 0)
            tmp.push_back(v[i] - v[i-1]);
    }
    sort(v.begin(), v.end());
    int prev = tmp[0];
    for(int i = 1; i<tmp.size(); ++i)
        prev = gcd(prev, tmp[i]);
    int ans = 0;
    for(int i=0; i<tmp.size(); ++i)
        ans += tmp[i] / prev - 1;
    cout<<ans;
    return 0;
}