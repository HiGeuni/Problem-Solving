#include<bits/stdc++.h>
using namespace std;

vector<int>dp, visited;
vector<vector<int>>v;

int dfs(int curNode){
	if(dp[curNode]) return dp[curNode];
	dp[curNode] = 1;
	int ans = 1;
	for(int i=0; i<v[curNode].size(); ++i){
		int nextNode = v[curNode][i];
		if(dp[nextNode]) continue;
		ans += dfs(nextNode);
	}
	dp[curNode] = ans;
	return ans;
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, r, q, s, d;
	cin>>n>>r>>q;
	v.resize(n+1);
	dp.resize(n+1, 0);
	for(int i=0; i<n-1; ++i){
		cin>>s>>d;
		v[s].push_back(d);
		v[d].push_back(s);
	}
	dfs(r);
	for(int i=0; i<q; ++i){
		cin>>d;
		cout<<dp[d]<<'\n';
	}
	return 0;
}
