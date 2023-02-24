// 받지 않는 경우를 생각하지 않아서 틀림!
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;

struct compare{
    bool operator()(const pii a, const pii b){
        if(a.first > b.first){
            return true;
        }else if (a.first == b.first)
        {
            return a.second < b.second;
        }
        return false;
    }
};

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int N, ta, tb, today = 1;
    ll res = 0;
    cin>>N;
    priority_queue<pii, vector<pii>, compare> pq;
    priority_queue<int, vector<int>, greater<int> >ans;
    for(int i=0; i<N; ++i){
        cin>>ta>>tb;
        pq.push(make_pair(ta, tb));
    }
    while(!pq.empty()){
        pii t = pq.top(); pq.pop();
        if(t.first >= today){
            ans.push(t.second);
            today += 1;
        }else{
            if(t.second > ans.top()){
                ans.pop();
                ans.push(t.second);
            }
        }
    }
    while(!ans.empty()){
        res += ans.top();
        ans.pop();
    }
    cout<<res<<'\n';
    return 0;
}
