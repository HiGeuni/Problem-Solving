#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>

int main(){
    int n;
    cin>>n;
    vector<int>v(n);
    for(int &x : v)
        cin>>x;
    vector<pii>top;
    vector<int>ans;
    ans.push_back(0);
    top.push_back({1, v[0]});
    for(int i=1; i<n; ++i){
        if(v[i] > top.back().second){
            while(top.size()!=0 && v[i] > top.back().second)
                top.pop_back();
            if(top.size()==0)
                ans.push_back(0);
            else{
                ans.push_back(top.back().first);
                if(top.back().second == v[i])
                    top.pop_back();
            }
        }
        else{
            ans.push_back(top.back().first);
        }
        top.push_back({i+1, v[i]});
    }
    for(auto & x : ans){
        cout<<x<<" ";
    }
    return 0;
}