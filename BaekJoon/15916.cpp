#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
vector<ll>graph;

int main() {
	long long tmp;
	long long n, k;
	cin >> n;
	graph.push_back(0);
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		graph.push_back(tmp);
	}
	cin >> k;
	if (k==graph[1]) {
		printf("T");
		return 0;
	}
	for (int i = 2; i <= n; i++) {
		if (graph[i] == k * i) {
			printf("T");
			return 0;
		}
		if (graph[i - 1] > k*(i - 1) && graph[i] < k*i) {
			printf("T");
			return 0;
		}
		else if (graph[i - 1] < k*(i - 1) && graph[i] > k*i) {
			printf( "T");
			return 0;
		}
	}
	printf("F");
	return 0;
}
