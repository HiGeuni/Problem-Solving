#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int>pii;

int main(){
    int n;
    cin>>n;
    vector<int>hp(101);
    vector<pii>pleasure(n);
    for(int i=0;i<n; ++i) cin>>pleasure[i].first;
    for(int i=0;i<n; ++i) cin>>pleasure[i].second;
    sort(pleasure.begin(), pleasure.end());
    for(int i=0;i<n; ++i){
        int curHp = pleasure[i].first;
        for(int j=100;j>curHp; --j) {
            hp[j] = max(hp[j], hp[j-curHp] + pleasure[i].second);
        }
    }
    cout<<hp[100];
    return 0;
}