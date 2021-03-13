#include<bits/stdc++.h>
using namespace std;

int main() {
	vector<int>v;
	int q;
	cin >> q;
	for (int i = 0; i < q; ++i) {
		string cmd;
		cin >> cmd;
		if (cmd == "push") {
			int x;
			cin >> x;
			v.push_back(x);
		}
		else if(cmd == "pop"){
			if (v.size() == 0) cout << -1 << "\n";
			else {
				cout << v.back()<<"\n";
				v.pop_back();
			}
		}
		else if (cmd == "size") {
			cout << v.size()<<"\n";
		}
		else if (cmd == "empty") {
			cout << ((v.size() == 0) ? 1 : 0) << "\n";
		}
		else if (cmd == "top") {
			cout << ((v.size() == 0) ? -1 : v[v.size()-1]) << "\n";
		}
	}
	return 0;
}
