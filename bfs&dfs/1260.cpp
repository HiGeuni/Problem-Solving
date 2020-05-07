#include<iostream>
#include<algorithm>
#include<queue>
#include<string.h>
#include<stdlib.h>
using namespace std;
vector<int>graph[1010];
int visited[1010];
int N, M, V;
queue<int>bfs_st;

void dfs(int index) {
	if (visited[index] == 1) return;
	visited[index] = 1;
	cout << index<<" ";
	for (int i = 0; i < graph[index].size(); i++) {
		dfs(graph[index][i]);
	}
}

void bfs(int index) {
	bfs_st.push(index);
	visited[index] = 1;
	while (bfs_st.size()) {
		int cur = bfs_st.front();
		bfs_st.pop();
		cout << cur << " ";

		for (int i = 0; i < graph[cur].size(); i++) {
			if (visited[graph[cur][i]] != 1) {
				visited[graph[cur][i]] = 1;
				bfs_st.push(graph[cur][i]);
			}
		}
	}
}

int main() {
	cin >> N >> M >> V;
	for (int i = 0; i < M; i++) {
		int to, from;
		cin >> from >> to;
		graph[from].push_back(to);
		graph[to].push_back(from);
	}

	for (int i = 1; i <= N; i++) {
		sort(graph[i].begin(), graph[i].end());
	}
	dfs(V);
	cout << endl;
	memset(visited, 0, sizeof(visited));
	bfs(V);
	return 0;
}
