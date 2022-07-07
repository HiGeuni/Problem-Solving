#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

int m[9][9];
int ans[9][9];
vector<pii> v;

void recursive(int idx){
	if(idx == v.size()){
		for(int i=0; i<9; ++i)
			for(int j=0; j<9; ++j)
				ans[i][j] = m[i][j];
		return;
	}
	pii cur = v[idx];
	int bit_ = 0;
	//열과 행
	for(int i=0; i<9; ++i){
		if(m[cur.first][i] != 0)
			bit_ |= 1<<(m[cur.first][i]-1);
		if(m[i][cur.second] != 0)
			bit_ |= 1<<(m[i][cur.second]-1);
	}
	//네모
	for(int i=0; i<3; ++i){
		for(int j=0; j<3; ++j){
			int nx = (cur.first/3) * 3 + i;
			int ny = (cur.second/3) * 3 + j;
			if(m[nx][ny] != 0)
				bit_ |= 1<<(m[nx][ny]-1);
		}
	}
	// 칠하고 다음으로 넘어가기
	for(int i=0; i<9; ++i){
		if(!(bit_ & (1<<i))){
			m[cur.first][cur.second] = i+1;
			recursive(idx + 1);
			m[cur.first][cur.second] = 0;
		}
	}
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	// input
	for(int i=0; i<9; ++i){
		for(int j=0; j<9; ++j){
			cin>>m[i][j];
			if(!m[i][j])
				v.push_back({i, j});
		}
	}
	recursive(0);
	for(int i=0; i<9; ++i){
		for(int j=0; j<9; ++j){
			cout<<ans[i][j]<<" ";
		}
		cout<<'\n';
	}
	return 0;
}
