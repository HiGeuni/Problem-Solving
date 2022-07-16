#include<bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int tc, n, num;
	char cmd;
	cin >> tc;
	for (int i = 0; i < tc; ++i) {
		multiset<int>q;
		cin >> n;
		for (int j = 0; j < n; ++j) {
			cin >> cmd >> num;
			if (cmd == 'I') {
				q.insert(num);
			}
			else {
				if (q.empty()) {
					continue;
				}
				if (num == -1) {
					q.erase(q.begin());
				}
				else {
					auto it = q.end();
					q.erase(--it);
				}
			}
		}
		if (q.empty()) {
			cout << "EMPTY" << '\n';
		}
		else {
			auto it = q.end();
			cout << *(--it) << " " << *q.begin() << '\n';
		}
	}
	return 0;
}
