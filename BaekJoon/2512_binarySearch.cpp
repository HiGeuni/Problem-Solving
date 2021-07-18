#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int N, total;
    cin>>N;
    vector<int>assets(N);
    for(auto & x : assets) cin>>x;
    sort(assets.begin(), assets.end());
    cin>>total;
    int ans = 0;
    int l=0, r=total;
    while(l<=r){
        int mid = (l+r)/2;
        int tmp = 0;
        for(int i=0;i<N; ++i){
            if(assets[i] < mid){
                tmp += assets[i];
            }else{
                tmp += mid;
            }
        }
        if( tmp > total){
            r = mid -1;
        }
        else{
            ans = max(ans, mid);
            l = mid + 1;
        }
    }
    if(ans == total){
        ans = assets.back();
    }
    cout<<ans;
    return 0;
}