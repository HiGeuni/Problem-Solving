#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, tmp;
    vector<int>v, ans;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> tmp;
        v.push_back(tmp);
    }
    stack<int>s;
    for (int i = n-1; i >= 0; --i) {
        while (!s.empty() && s.top() <= v[i])
            s.pop();

        if (s.empty()) ans.push_back(-1);
        else {
            ans.push_back(s.top());
        }
        s.push(v[i]);
    }
    for (int i = ans.size()-1; i >= 0; --i) {
        cout << ans[i] << ' ';
    }
    cout << '\n';

    return 0;
}
