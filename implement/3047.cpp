//3047 ABC
//20200227

#include<bits/stdc++.h>
using namespace std;

int main() {
	string str;
	vector<int>v(3);
	for(int i=0; i<3; ++i)
		cin>>v[i];
	cin>>str;
	sort(v.begin(), v.end());
	for(int i=0; i<3; ++i)
		cout<<v[str[i] - 'A']<<" ";
	return 0;
}
