#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	int tc, t;
	cin >> tc;
	for (int i = 0; i < tc; ++i) {
		priority_queue<ll, vector<ll>, greater<ll>>pq;
		ll answer = 0, num;
		cin >> num;
		for (int j = 0; j < num; ++j) {
			cin >> t;
			pq.push(t);
		}
		while(pq.size() != 1) {
			ll t1 = pq.top(); pq.pop();
			ll t2 = pq.top(); pq.pop();
			ll t3 = t1 + t2;
			answer += t3;
			pq.push(t3);

		}
		cout << answer << endl;
	}
	return 0;
}
