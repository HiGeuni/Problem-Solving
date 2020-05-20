#include<iostream>
#include<vector>
using namespace std;
typedef long long ll;
vector<int>tree;

ll r, l, N, Ham, hong, ans, res;

int main() {
	cin.tie(NULL);
	cin >> N >> Ham;
	for (int i = 0; i < N; i++)
	{
		ll tmp;
		cin >> tmp;
		tree.push_back(tmp);
		if (tmp > hong) hong = tmp;
	}
	r = hong; l = 1;
	while (l <= r) {
		ll res = 0;
		ll mid = (r + l) / 2;
		for (int i = 0; i < N; i++) {
			res += (tree[i] / mid);
		}
		if (res >= Ham) {
			if (ans < mid) ans = mid;
			l = mid+1;
		}
		else r = mid - 1;
	}
	cout << ans;
	return 0;
}
