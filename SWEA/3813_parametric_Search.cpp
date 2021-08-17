#include<iostream>
using namespace std;

int chk[10] = {0,};
void dfs(int n, int idx, int arr[4]){
    if(n == 10){
        return;
    }
    if(idx == 4){
        for(int i=0;i<4; ++i){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i=n;i<10; ++i){
        if(chk[i]==0){
            chk[i] = 1;
            arr[idx] = i;
            dfs(i, idx+1, arr);
            arr[idx] = 0;
            chk[i] = 0;
        }
    }
    return;
}

int main(){
    dfs(0,0,{0,0,0,0});
}