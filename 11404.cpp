#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int g[101][101];
int a, b, c;

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			g[i][j] = 1e9;
			if (i == j) g[i][j] = 0; 
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		a--; b--;
		g[a][b] = min(g[a][b], c);
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (g[i][j] >= (int)1e9) g[i][j] = 0;
			cout << g[i][j] << " ";
		}
		cout << endl;
	}
}
