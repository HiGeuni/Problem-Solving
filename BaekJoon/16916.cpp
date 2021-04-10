#include<bits/stdc++.h>
using namespace std;

vector<int>failure(string s){
    vector<int>res(s.size());
    int j=0;
    for(int i=1; i<s.size(); ++i){
        while(j>0 && s[j] != s[i]){
            j = res[j-1];
        }
        if(s[j] == s[i]){
            res[i] = ++j;
        }
    }
    return res;
}

bool KMP(string s, string pat){
    bool flag = false;
    vector<int>table = failure(pat);
    int sSize = s.size();
    int patSize = pat.size();
    int j=0;
    for(int i=0;i<sSize; ++i){
        while(j>0 && s[i] != pat[j]){
            j = table[j-1];
        }
        if(s[i] == pat[j]){
            if(j == patSize-1) {
                flag = true;
                break;
            }
            else{
                j++;
            }
        }
    }
    return flag;
}

int main()
{
    string s1, s2;
    cin>>s1>>s2;
    cout<<KMP(s1, s2) ? 1 : 0;
    return 0;
}