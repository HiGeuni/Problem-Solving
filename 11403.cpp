//11403 경로찾기
//20200225

#include<bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
	vector<vector<int>>v(n, vector<int>(n));
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
				cin>>v[i][j];
	for(int i=0; i<n; ++i)
		for(int j=0; j<n; ++j)
			for(int k=0; k<n; ++k)
				if(v[j][i] && v[i][k])
					v[j][k] =1;
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j)
			cout<<v[i][j]<<" ";
		cout<<endl;
	}
	return 0;
			
}
