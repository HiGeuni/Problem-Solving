#include<bits/stdc++.h>
using namespace std;

vector<int>v;

int main(){
	int k, ans = -2e9;
	cin>>k;
	v.resize(k);
	for(int i=0; i<k; i++){
		cin>>v[i];
	}
	sort(v.begin(), v.end());
	for(int i=0; i<k; i++){
		ans = max(ans, (k-i)*v[i]);
	}
	cout<<ans;
	return 0;
}
