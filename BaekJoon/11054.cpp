#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    vector<vector<int>>lis(2, vector<int>(n));
    for(int i=0; i<n; ++i)
        cin>>v[i];

    for(int i=0; i<n; ++i){
        int min_ = 0;
        for(int j=0; j<i; ++j){
            if(v[i] > v[j])
                min_ = max(min_, lis[0][j]);
        }
        lis[0][i] = min_ + 1;
    }
    int ans = 0;
    for(int i=n-1; i>=0; --i){
        int min_ = 0;
        for(int j=n-1; j>=i; --j){
            if(v[i] > v[j])
                min_ = max(min_, lis[1][j]);
        }
        lis[1][i] = min_ + 1;
        ans = max(ans, lis[1][i] + lis[0][i]);
    }

    cout<<ans-1<<'\n';
    return 0;
}
