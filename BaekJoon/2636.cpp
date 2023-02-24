#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int N, M;
	cin >> N >> M;
	vector<vector<int> >v(N, vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> v[i][j];
		}
	}
	int ans = 0;
	int num_cheese = 0;
	// 공기와 닿아있는 부분 찾고 이건 네 모서리에서 BFS 진행하기
	// 닿아있는 부분 체크하고, 
	// 녹이기
	// 반복
	int dx[4] = {0, 0, N-1, N-1};
	int dy[4] = { 0, M - 1, 0, M - 1 };
	int ddx[4] = { 0,0,1,-1 };
	int ddy[4] = { 1,-1, 0,0 };
	while (true) {
		bool flag = true;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (v[i][j] == 1) flag = false;
			}
		}
		if (flag) break;
		num_cheese = 0;
		ans += 1;
		vector<vector<int> >visited(N, vector<int>(M, 0));
		for (int i = 0; i < 4; ++i) {
			if (visited[dx[i]][dy[i]] != 0) continue;
			deque<pair<int, int>>dq;
			dq.push_back({ dx[i], dy[i] });
			while (!dq.empty()) {
				pair<int, int>cur = dq.front();
				dq.pop_front();
				for (int j = 0; j < 4; ++j) {
					int nx = cur.first + ddx[j];
					int ny = cur.second + ddy[j];
					if (0 <= nx && nx < N && 0 <= ny && ny < M) {
						if (visited[nx][ny] == 0) {
							if (v[nx][ny] == 0) {
								visited[nx][ny] = 1;
								dq.push_back({ nx, ny });
							}
							else {
								visited[nx][ny] = 2;
							}
						}
					}
				}
			}
		}
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				if (visited[i][j] == 2) {
					v[i][j] = 0;
					num_cheese += 1;
				}
			}
		}
	}
	cout << ans << '\n' << num_cheese<<'\n';

	return 0;
}
