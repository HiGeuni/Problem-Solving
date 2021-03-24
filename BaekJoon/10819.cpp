#include<bits/stdc++.h>
using namespace std;

int main() {
    int n,fact = 1, ans = -1;
    cin>>n;
    vector<int>v(n);
    for(int i=0;i<n; ++i){
        cin>>v[i];
        fact *= (i+1);
    }
    for(int i=0;i<fact; ++i){
        int tmp = 0;
        for(int j=0;j<n-1; ++j){
            tmp += abs(v[j]-v[j+1]);
        }
        ans = max(tmp, ans);
        next_permutation(v.begin(), v.end());
    }
    cout<<ans;
    return 0;
}