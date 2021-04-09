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
/*
typedef pair<int,int> pii;

int main(){
    int th, tm;
    string ts;
    vector<pii>v(3);
    for(int i=0;i<3; ++i){
        scanf("%d:%d", &th, &tm);
        v[i] = {th, tm};
    }
    unordered_map<string, int>enter;
    int ans = 0;
    while(scanf("%d:%d", &th, &tm)){
        cin>>ts;
        if(th<v[0].first || (th==v[0].first && tm <=v[0].second)){
            enter[ts] = 1;
        }
        else if(th)
    }
    return 0;
}
*/
/*
const int swtch[10][5] = {
        {0,1,2,-1,-1},
        {3,7,9,11,-1},
        {4,10,14,15,-1},
        {0,4,5,6,7},
        {6,7,8,10,12},
        {0,2,14,15,-1},
        {3,14,15,-1,-1},
        {4,5,7,14,15},
        {1,2,3,4,5},
        {3,4,5,9,13}
};

int solve(vector<int> & v, int numSwitch){

}

int main(){
    int tc;
    cin>>tc;
    for(int i=0;i<tc; ++i){
        vector<int>stt(12);
        for(auto & x : stt) cin>>stt[i];
    }
}*/

