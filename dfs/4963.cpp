//4963 섬의 개수

#include <bits/stdc++.h>
using namespace std;

//variations 
int visited[50][50]={0};
int arr[50][50];
int dx[8]={-1,-1,-1,0,0,1,1,1};
int dy[8]={1,0,-1,1,-1,-1,0,1};
int n,m;

//find island
void dfs(int x,int y){
    visited[x][y]=1;
    for(int i=0;i<8;i++){
        int nx=x+dx[i];
        int ny=y+dy[i];
 
        if(nx>=m || nx<0 || ny>=n || ny<0){
            continue;
        }
 
        if(visited[nx][ny]==0 && arr[nx][ny]==1){
            dfs(nx,ny);
        }
    }
 
}
    
//input & solve
int main(){
    int cnt;
    while(1){
		scanf("%d%d",&n,&m);
        if(n==0 && m==0){
            return 0;
        }
 
		memset(visited, 0, sizeof(visited));
        cnt=0;
 
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cin>>arr[i][j];
            }
        }
        
 
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j]==0 && arr[i][j]==1){
                    dfs(i,j);
                    cnt++;
                }
            }
        }
        cout<<cnt<<endl;
 
    }
 
    return 0;
}
      
