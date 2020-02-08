#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int LIS(vector<int>&v) {
	int cnt = 0;
	vector<int>ans(1, -1);
	for (int num : v) {
		if (num > ans.back()) {
			ans.push_back(num);
			cnt++;
		}
		else {
			vector<int>::iterator iter = lower_bound(ans.begin(), ans.end(), num);
			*iter = num;
		}
	}
	return cnt;
}

int main() {
	int n, ans;
	while (cin >> n) {
		vector<int>v(n, -1);
		for (int i = 0; i < n; ++i)
			cin>>v[i];
		ans = LIS(v);
		cout << ans << endl;
	}
	return 0;
}
