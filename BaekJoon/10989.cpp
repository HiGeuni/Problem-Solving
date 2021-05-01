#include<iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int arr[10001] = {0, };
    int n, tmp;
    cin>>n;
    for(int i=0;i<n; ++i){
        cin>>tmp;
        arr[tmp] += 1;
    }
    for(int i=1;i<10001; ++i){
        if(arr[i] == 0) continue;
        else{
            for(int j=0;j<arr[i]; ++j){
                cout<<j<<'\n';
            }
        }
    }
    return 0;
}