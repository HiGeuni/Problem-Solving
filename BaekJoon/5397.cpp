#include<bits/stdc++.h>
using namespace std;

int main() {
	int tc;
	cin >> tc;
	for (int i = 0; i < tc; ++i) {
		list<char>ans;
		string s;
		cin >> s;
		auto it = ans.end();
		for (int i = 0; i < s.size(); ++i) {
			switch (s[i]) {
			case '<':
				if (it != ans.begin()) it--;
				break;
			case '>':
				if (it != ans.end()) it++;
				break;
			case '-':
				if (it != ans.begin())it = ans.erase(--it);
				break;
			default:
				ans.insert(it, s[i]);
				break;
			}
		}
		for (char s : ans) {
			cout << s;
		}
		cout << '\n';
	}
	return 0;
}
