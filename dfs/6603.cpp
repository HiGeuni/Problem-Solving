//6603 로또

#include<bits/stdc++.h>
using namespace std;

void dfs(int s, int depth, int k, int lotto[], int comb[]){
	if(depth == 6){
		for(int i=0; i<6; ++i){
			cout<<comb[i]<<' ';
		}
		cout<<endl;
		return;
	}
	for(int i= s; i<k; ++i){
		comb[depth] = lotto[i];
		dfs(i+1, depth+1, k, lotto, comb);
	}
}

int main(){
	int lotto[13];
	int comb[13];
	int k;
	while(cin>>k && k!=0){
		for(int i=0; i<k; ++i){
			cin>>lotto[i];
		}
		dfs(0,0,k,lotto, comb);
		cout<<'\n';
	}
	return 0;
}
