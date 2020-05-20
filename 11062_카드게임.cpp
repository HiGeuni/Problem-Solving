#include<bits/stdc++.h>
using namespace std;

int ans =0, flag;
vector<int>card;
int dp[1001][1001];

int game(int s, int e){
	if (dp[s][e]) return dp[s][e];
	if(s==e){
		if(flag ==1) return card[s];
		else return 0;
	}
	if((e-s)%2 == flag)
		return min(game(s+1,e), game(s,e-1));
	return dp[s][e] = max(game(s+1,e)+card[s], game(s,e-1)+card[e]);
}

int main(){
	int tc, N, tmp;
	cin.tie();
	ios_base::sync_with_stdio(0);
	cin>>tc;
	for(int i=0; i<tc; i++){
		memset(dp, 0, sizeof(dp));
		cin>>N;
		card.clear();
		card.resize(N);
		for(int j=0; j<N; j++)
			cin>>card[j];
		if(N%2 == 0) flag = 0;
		else flag = 1;
		cout<<game(0, N-1)<<endl;
	}
	return 0;
}
