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
    int ans;
    string a;
    while(true){
        cin>>a;
        if(a == ".") break;
        vector<int> tmp = makeTable(a);
        if(a.size() % (a.size() - tmp[tmp.size()-1])) cout<<1<<'\n';
        else cout<<a.size() / (a.size() - tmp[tmp.size()-1])<<'\n';
    }
    return 0;
}