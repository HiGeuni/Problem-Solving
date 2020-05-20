#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int>v(101000, -1);

int main() {
	int n, from, to;
	cin >> n;
	for (int i = 0; i < n; ++i) 
		cin >> v[i];
	vector<int>ans(1,0);
	for (int num : v) {
		if (num < 0) break;
		if (ans.back() < num) 
			ans.push_back(num);
		else {
			auto it = lower_bound(ans.begin(), ans.end(), num);
			*it = num;
		}
	} 
	cout << n - ans.size()+1;
	return 0;
}
