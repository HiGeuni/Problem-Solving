#20200426
#1068 트리

#include<vector>
#include<iostream>
using namespace std;

vector< vector<int> >graph;
int ans =0;

void dfs(int idx, int erase){
	if(erase == idx) return;
	if(graph[idx].size() == 0){
		ans+=1;
		return;
	}
	else if(graph[idx].size() == 1){
		if(graph[idx][0] == erase){
			ans+=1;
			return;
		}
	
	}
	for(int i=0; i<graph[idx].size(); ++i)
		dfs(graph[idx][i], erase);
	return;
}

int main(){
	int root;
	int num_node;
	int tmp;
	int erase_node;
	cin>>num_node;
	graph.resize(num_node);
	//make graph
	for(int i=0; i<num_node; ++i){
		cin>>tmp; //parent
		if(tmp == -1) root = i;
		else graph[tmp].push_back(i);
	}
	cin>>erase_node;
	dfs(root, erase_node);
	cout<<ans;
	return 0;
}
