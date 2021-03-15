#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, top = 0, tmp;
    cin>>n;
    vector<int>v;
    vector<char>ans;
    bool flag = true;
    while(n){
        cin>>tmp;
        if(top < tmp){
            for(int i=top+1; i<=tmp; ++i){
                v.push_back(i);
                ans.push_back('+');
            }
            top = tmp;
        }
        if(v.back() == tmp){
            v.pop_back();
            ans.push_back('-');
        }
        else
            flag = false;

        n--;
    }
    if (flag)
        for(auto &x : ans)
            cout<<x<<'\n';
    else
        cout<<"NO"<<'\n';
    return 0;
}