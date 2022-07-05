#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int N, M, s, d, w;
	cin>>N>>M;
	vector<int>v(N+1), v2(N+2, 0);

	for(int i=1; i<=N; ++i){
		cin>>v[i];
	}
	for(int i=0; i<M; ++i){
		cin>>s>>d>>w;
		v2[s] += w;
		v2[d+1] -= w;
	}
	for(int i=1; i<=N; ++i){
		v2[i] += v2[i-1];
		cout<<v[i] + v2[i]<<" ";
	}
	cout<<'\n';
	return 0;
}
