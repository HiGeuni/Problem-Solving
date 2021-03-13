#include<bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	int q;
	cin >> q;

	list<char>ls;

	for (char x : s)
		ls.push_back(x);

	//init
	list<char>::iterator it = ls.end();

	for (int i = 0; i < q; ++i) {
		char cmd;
		cin >> cmd;
		switch (cmd) {
		case 'P':
			char x;
			cin >> x;
			ls.insert(it, x);
			break;
		case 'L':
			if(it != ls.begin()) it--;
			break;
		case 'B':
			if (it != ls.begin()) {
				it = ls.erase(--it);
			}
			break;
		case 'D':
			if(it!= ls.end()) it++;
			break;
		default:
			break;
		}
	}
	for (char x : ls)
		cout << x;
	return 0;
}
