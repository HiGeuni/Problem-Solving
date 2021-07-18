#include<iostream>
#include<vector>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;
typedef pair<int,int> pii;
int main(){
    int C, tmp, c1, c2, N;
    cin>>C>>N;
    vector<int>chickens(C);
    vector<bool>visited(C, false);
    for(int i=0;i<C; ++i){
        cin>>chickens[i];
    }
    sort(chickens.begin(), chickens.end());
    priority_queue<pii, vector<pii>, greater<>>pqCow;
    for(int i=0;i<N; ++i){
        cin>>c1>>c2;
        pqCow.push({c2, c1});
    }
    int cnt = 0;
    while(!pqCow.empty()){
        pii curCow = pqCow.top();pqCow.pop();
        for(int i=0;i<C; ++i){
            if(visited[i]) continue;
            if(curCow.second <= chickens[i] && curCow.first >= chickens[i]){
                cnt += 1;
                visited[i] = true;
                break;
            }
        }
    }
    cout<<cnt;
    return 0;
}