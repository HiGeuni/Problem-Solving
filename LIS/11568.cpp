#include<iostream>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

vector<int>v(500001, -1);

int main() {
	int n, from, to;
	cin >> n;
	for (int i = 0; i < n; ++i)
		cin>>v[i];
	vector<int>ans(1,0);
	for (int i = 0; i < 500001; ++i) {
		if (v[i] < 0) continue;
		if (ans.back() < v[i]) 
			ans.push_back(v[i]);
		else {
			auto it = lower_bound(ans.begin(), ans.end(), v[i]);
			*it = v[i];
		}
	} 
	cout << ans.size()-1;
	return 0;
}
