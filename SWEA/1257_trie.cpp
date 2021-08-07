#include<cstdio>
#include<iostream>
#include<string>
#include<string.h>
#include<vector>
using namespace std;

#define ALPHABETS_CNT 27
#define MAXN 1000001

struct Trie;
Trie* myAlloc();
string s;
int nodeCnt = 0;
int cnt;
int K;
vector<char>ans;

struct Trie {
    Trie* _children[ALPHABETS_CNT];
    bool end;
    void add(const char* word) {
        if(*word == 0){
            end = true;
        }
        else if (*word != 0) {
            if (_children[*word - 'a'] == nullptr) _children[*word - 'a'] = myAlloc();
            _children[*word - 'a']->add(word + 1);
        }
    }

    Trie* get(const char* word) {
        if (*word != 0) {
            if (_children[*word - 'a'] != nullptr) return _children[*word - 'a']->get(word + 1);
            return nullptr;
        }
        return this;
    }
    void clear() {
        for (int i = 0; i < ALPHABETS_CNT; i++) {
            _children[i] = nullptr;
        }
    }
};

void dfs(Trie * root){
    bool flag = false;
    Trie * tmp = root;
    if(tmp->end){
        cnt += 1;
//        printf("%d ", cnt);
//        for(auto x: ans){
//            printf("%c", x);
//        }
//        printf("\n");
    }
    if(cnt == K) return;
    for(int i=0; i<27; ++i){
        if(tmp->_children[i]){
            ans.push_back('a'+i);
            dfs(tmp->_children[i]);
            if(cnt == K) return;
            ans.pop_back();
        }
    }
}

Trie Node[MAXN];

Trie* myAlloc() {
    Trie* ret = &Node[nodeCnt++];
    ret->clear();
    ret->end = false;
    return ret;
}

int main(){
    int TC;
    scanf("%d", &TC);
    for(int tc=1; tc<=TC; ++tc){
        ans.clear();
        nodeCnt = 0;
        Trie* root = myAlloc();
        cnt = 0;
        scanf("%d", &K);
        cin>>s;
        char tmp[400];
        for(int i=0; i<=s.size(); ++i){
            for(int j=1;j<=s.size()-i; ++j ){
                memset(tmp, 0, s.size());
                string str;
                str = s.substr(i, j);
//                str.push_back('{');
                strcpy(tmp, str.c_str());
                root->add(tmp);
//                printf("%d %d %s\n", i, j, tmp);
            }

        }
        dfs(root);
        printf("#%d ", tc);
        if(ans.back() == '{') ans.pop_back();
        if(ans.size() == 0){
            printf("none\n");
        }else {
            for (auto x : ans) {
                printf("%c", x);
            }
            printf("\n");
        }
    }
    return 0;
}