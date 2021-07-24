#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<cmath>
using namespace std;

int main(){
    int N;
    cin>>N;
    vector<string>s;
    vector<pair<int,int>>v(26);
    for(int i=0;i<26;++i)
        v[i].second = i;
    s.resize(N);
    for(int i=0;i<N; ++i){
        cin>>s[i];
        for(int j=0;j<s[i].size(); ++j) {
            v[s[i][j] - 'A'].first += pow(10, s[i].size() - j);
        }
    }
    sort(v.rbegin(), v.rend());
    map<char, int>m;
    int num =9;
    for(int i=0;i<26; ++i){
        m[char('A' + v[i].second)] = num--;
    }
    int ans =0;
    for(int i=0;i<N; ++i){
        int tmp = 0;
        for(int j=0;j<s[i].size(); ++j){
            tmp*=10;
            tmp += m[s[i][j]];
        }
        ans += tmp;
    }
    cout<<ans;
    return 0;
}