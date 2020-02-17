//1377 버블 소트
//2020-02-17

#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int main(){
	int n;
	int res = 0;
	cin>>n;
	vector<pii>v(n);
	for(int i=0; i<n; ++i){
		cin>>v[i].first;
		v[i].second = i;
	}
	sort(v.begin(),v.end());
	for (int i = 0; i < n; i++)
        res = max(res, v[i].second - i);
	cout<<res+1;
	return 0;
}
