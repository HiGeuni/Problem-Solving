#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, target;
	cin >> n;
	vector<int>v(n);
	for (int i = 0; i < n; ++i) 
		cin >> v[i];
	sort(v.begin(), v.end());
	cin >> target;
	int start=0, end=n-1, ans = 0;
	while (start < end) {
		if (v[start] + v[end] == target) {
			ans += 1;
			end--;
		}
		else if (v[start] + v[end] > target) {
			end--;
		}
		else {
			start++;
		}
	}
	cout << ans;
	return 0;
}
