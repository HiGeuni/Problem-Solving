#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n, tmp;
    cin>>n;
    priority_queue<int>pq;
    for(int i=0;i<n; ++i){
        cin>>tmp;
        pq.push(-tmp);
    }
    for(int i=1; i<n; ++i){
        for(int j=0;j<n; ++j) {
            cin >> tmp;
            if(-pq.top()<tmp){
                pq.pop();
                pq.push(-tmp);
            }
        }
    }
    cout<<-pq.top();
    return 0;
}