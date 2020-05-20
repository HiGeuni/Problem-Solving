//2583 영역 구하기
//20200225

#include<bits/stdc++.h>
using namespace std;

int m, n, k, cnt;
int arr[101][101];
bool chk[101][101] = {false, };
const int dx[] = {0,0,1,-1};
const int dy[] = {1,-1, 0, 0};

void dfs(int x, int y){
	int nx, ny;
	if(chk[x][y] == true) return ;
	chk[x][y] = true;
	cnt++;
	for(int i=0; i<4; ++i){
		nx = x + dx[i];
		ny = y + dy[i];
		if(nx<m && ny<n && nx>=0 && ny>=0){
			if(chk[nx][ny] == false && arr[nx][ny] == 0){
				dfs(nx, ny);
			}
		}
	}
}


int main(){
	int tmp[4], tmp_ans;
	vector<int>ans;
	cin>>m>>n>>k;
	for(int i=0; i<k; ++i){
		for(int j=0; j<4; ++j)
			cin>>tmp[j];
		for(int j=tmp[0]; j<tmp[2]; ++j)
			for(int l=tmp[1]; l<tmp[3]; ++l){
				arr[l][j] = 1;
				chk[l][j] = true;
			}
	}
	/*
	for(int i=0; i<m; ++i){
		for(int j=0; j<n; ++j){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}*/
	for(int i=0; i<m; ++i){
		for(int j=0; j<n; ++j){
			if(chk[i][j] == false && arr[i][j] == 0){
				cnt =0;
				dfs(i,j);
				ans.push_back(cnt);
			}
		}
	}
	sort(ans.begin(), ans.end());
	cout<<ans.size()<<endl;
	for(int i=0; i<ans.size(); ++i){
		cout<<ans[i]<<" ";
	}
	return 0;
}
