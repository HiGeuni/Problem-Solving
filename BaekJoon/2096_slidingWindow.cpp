#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int>minDp(3 ,2e9);
    vector<int>maxDp(3, -1);

    for(int i=0; i<n; ++i){
        int input[3];
        cin>>input[0]>>input[1]>>input[2];
        if(i == 0){
            for(int j=0;j<3; ++j){
                minDp[j] = input[j];
                maxDp[j] = input[j];
            }
            continue;
        }
        int tmp[3];
        for(int j=0;j<3; ++j) tmp[j] = minDp[j];
        minDp[0] = input[0] + min(tmp[0], tmp[1]);
        minDp[1] = input[1] + min(min(tmp[0], tmp[1]),tmp[2]);
        minDp[2] = input[2] + min(tmp[1], tmp[2]);
        for(int j=0;j<3; ++j) tmp[j] = maxDp[j];
        maxDp[0] = input[0] + max(tmp[0], tmp[1]);
        maxDp[1] = input[1] + max(max(tmp[0], tmp[1]),tmp[2]);
        maxDp[2] = input[2] + max(tmp[1], tmp[2]);
    }

    int maxAns = -1;
    int minAns = 2e9;
    for(int i=0; i<3; ++i){
        maxAns = max(maxAns, maxDp[i]);
        minAns = min(minAns, minDp[i]);
    }
    cout<<maxAns<<" "<<minAns;
    return 0;
}