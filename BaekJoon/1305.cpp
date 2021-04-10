#include<bits/stdc++.h>
using namespace std;

vector<int> makeTable(string pattern){
    int lenPat = pattern.size();
    vector<int>v(lenPat);
    // i == pattern, j == continuous
    int i,j=0;
    for(i=1; i<lenPat; ++i){
        while(j > 0 && pattern[i] != pattern[j]){
            j = v[j-1];
        }
        if(pattern[i] == pattern[j])
            v[i] = ++j;
    }
    return v;
}

int main(){
    int n;
    cin>>n;
    string a;
    cin>>a;
    vector<int>ans = makeTable(a);
    cout<<n - ans[n-1];
    return 0;
}
