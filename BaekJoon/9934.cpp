#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int>v((1<<(n)) - 1);
    vector<bool>flag((1<<(n))-1);
    vector<int>ans;
    for(auto & x : v)
        cin>>x;
    for(int i=0;i<n; ++i) {
        int cnt = 1;
        for (int j = 0; j < v.size(); ++j) {
            if (flag[j]) continue;
            if (cnt == 1) {
                ans.push_back(v[j]);
                flag[j] = true;
                cnt = 0;
            } else cnt++;
        }
    }
    int idx = ans.size()-1;
    for(int i=0;i<n; ++i){
        idx -= (i == 0) ? 0 : (1<<(i));
        int tmp = idx;
        for(int j=0; j<(1<<i); ++j){
            cout<<ans[idx++]<<" ";
        }
        cout<<"\n";
        idx = tmp;
    }
    return 0;
}