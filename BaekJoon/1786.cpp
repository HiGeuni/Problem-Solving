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

vector<int> kmp(string s1, string s2){
    vector<int>table = makeTable(s2);
    vector<int>ans;
    int lenS1 = s1.size();
    int lenS2 = s2.size();
    int j=0;
    for(int i=0; i<lenS1; ++i){
        while(j>0 && s1[i] != s2[j]){
            j = table[j-1];
        }
        if(s1[i] == s2[j]){
            if(j == lenS2 -1){
                ans.push_back(i-lenS2+2);
                j = table[j];
            } else{
                j++;
            }
        }
    }
    return ans;
}

int main(){
    string a,b;
    getline(cin, a);
    getline(cin, b);
    vector<int>ans = kmp(a,b);
    cout<<ans.size()<<'\n';
    for(int x : ans) cout<<x<<'\n';
    return 0;
}

