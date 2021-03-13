#include<bits/stdc++.h>
using namespace std;

int main() {
	int k, sum = 0;
	cin >> k;
	vector<int>v;
	for (int i = 0; i < k; ++i) {
		int tmp;
		cin >> tmp;
		if (tmp == 0) {
			sum -= v.back();
			v.pop_back();
		}
		else {
			sum += tmp;
			v.push_back(tmp);
		}
	}
	cout << sum;
	return 0;
}
