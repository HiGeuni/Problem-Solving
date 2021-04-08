#include<bits/stdc++.h>
using namespace std;

int main(){
    int tc;
    int n,m;
    cin>>tc;
    for(int i=0;i<tc; ++i){
        int minVal = 2e9;
        cin>>n>>m;
        vector<int>v1(n);
        vector<int>v2(m);
        for(auto & x : v1) cin>>x;
        for(auto & x : v2) {
            cin >> x;
            minVal = min(minVal ,x);
        }
        sort(v2.begin(), v2.end());
        int ans = 0;
        auto it1 = lower_bound(v2.begin(), v2.end(), minVal);
        for(int x : v1){
            auto it2 = upper_bound(v2.begin(), v2.end(), x);
            if(*(it2-1) == x){
                auto it3 = lower_bound(v2.begin(), v2.end(), x);
                ans += (it2-it1-(it2 - it3));
            }else {
                ans += (it2 - it1);
            }
        }
        cout<<ans<<'\n';
    }
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

