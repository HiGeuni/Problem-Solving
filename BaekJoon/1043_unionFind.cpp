#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int parent[51];

int getParent(int n){
    if(parent[n] == n) return n;
    else if(parent[n] == -1) return -1;
    return parent[n] = getParent(parent[n]);
}

void unionParent(int n, int m){
    int a = getParent(n);
    int b = getParent(m);
    if(a<b)
        parent[b] = a;
    else
        parent[a] = b;
}

int main(){
    int N, M, tmp, tmp2;
    cin>>N>>M;
    for(int i=0;i<N+1; ++i){
        parent[i] = i;
    }
    cin>>tmp;
    for(int i=0; i<tmp; ++i){
        cin>>tmp2;
        parent[tmp2] = -1;
    }
    int partyMember[52][52];
    for(int i=0;i<M; ++i){
        cin>>tmp;
        partyMember[i][0] = tmp;
        cin>>partyMember[i][1];
        for(int j=2; j<tmp+1; ++j){
            cin>>partyMember[i][j];
            unionParent(partyMember[i][j-1], partyMember[i][j]);
        }
    }
    int cnt = 0;
    for(int i=0;i<M; ++i){
        bool flag = true;
        for(int j=1; j<partyMember[i][0]+1; ++j){
            if(getParent(partyMember[i][j]) == -1){
                flag = false;
                break;
            }
        }
        if(flag){
            cnt += 1;
        }
    }
    cout<<cnt;
    return 0;
}