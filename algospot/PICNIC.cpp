#include<bits/stdc++.h>
using namespace std;

//두 명씩 짝을 짓는다.

//총 학생 수, picked,
int recursive(int n, vector<bool> visit, vector<vector<bool>>v1){
    int initVal = -1;
    for(int i=0;i<n; ++i){
        if(!visit[i]){
            initVal = i;
            break;
        }
    }

    if(initVal == -1) return 1;

    int retVal = 0;
    for(int i = initVal+1; i<n; ++i){
        if(!visit[i] && v1[initVal][i]){
            visit[i] = true;
            visit[initVal] = true;
            retVal += recursive(n, visit, v1);
            visit[i] = false;
            visit[initVal] = false;
        }
    }
    return retVal;
}

int main(){
    cin.tie();
    ios_base::sync_with_stdio();
    int tc;
    cin>>tc;
    for(int i=0;i<tc;++i){
        int numStudent, numPair, ta, tb;
        cin>>numStudent>>numPair;
        vector<vector<bool>>v(numStudent, vector<bool>(numStudent, false));
        vector<bool>visited(numStudent, false);
        for(int j=0;j<numPair; ++j){
            cin>>ta>>tb;
            v[ta][tb] = true;
            v[tb][ta] = true;
        }
        int ans = recursive(numStudent, visited, v);
        cout<<ans<<'\n';
    }
    return 0;
}