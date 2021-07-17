#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int GCD(int a, int b)
{
    if(b==0)return a;
    else return GCD(b,a%b);
}

int main(){
    cin.tie();
    ios_base::sync_with_stdio(false);
    int n;
    cin>>n;
    vector<int>v(n);
    vector<int>res;
    cin>>v[0];
    for(int i=1;i<n; ++i){
        cin>>v[i];
        res.push_back(v[i] > v[i-1] ? v[i] - v[i-1] : v[i-1] - v[i]);
    }
    int tmp = GCD(res[0], res[1]);
    for(int i=2;i<res.size(); ++i){
        tmp = GCD(res[i], tmp);
    }

    vector<int>ans;

    for(int i=2; i*i <= tmp; ++i){
        if(tmp % i == 0){
            ans.push_back(tmp/i);
            ans.push_back(i);
        }
    }

    ans.push_back(tmp);
    ans.erase(unique(ans.begin(),ans.end()),ans.end());
    sort(ans.begin(), ans.end());
    for(auto x : ans){
        cout<<x<< " ";
    }
    return 0;
}