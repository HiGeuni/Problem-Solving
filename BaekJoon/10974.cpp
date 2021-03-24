#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> v(n);
    int num = 1;
    for (int i = 0; i < n; ++i){
        v[i] = i + 1;
        num *= (i+1);
    }
    for(int i=0;i<num; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << v[j] << " ";
        }
        cout<<"\n";
        next_permutation(v.begin(), v.end());
    }
    return 0;
}