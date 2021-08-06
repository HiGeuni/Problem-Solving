#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;

#define ALPHABETS_CNT 27
#define MAXN 1000001

struct Trie;
Trie* myAlloc();
char s[404];
int nodeCnt = 0;
int cnt;
int K;
vector<char>ans;

struct Trie {
    Trie* _children[ALPHABETS_CNT];
    bool end;
    void add(const char* word) {
        if (*word != 0) {
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
    for(int i=0; i<27; ++i){
        if(tmp->_children[i]){
            flag = true;
            break;
        }
    }
    if(!flag) {
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
    return ret;
}

int main(){
    int TC;
    scanf("%d", &TC);
    for(int tc=1; tc<=TC; ++tc){
        fill(s, s+402, '\0');
        ans.clear();
        nodeCnt = 0;
        Trie* root = myAlloc();
        cnt = 0;
        scanf("%d", &K);
        scanf("%s", s);
        s[strlen(s)] = '{';
        for(int i=0; i<=strlen(s); ++i){
            root->add(s+i);
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