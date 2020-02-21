//11651 좌표 정렬하기 2
//20200221

#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

bool cmp(pii a, pii b){
	if(a.second < b.second)
		return true;
	else if(a.second == b.second)
		if(a.first < b.first)
			return true;
	return false;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n,a,b;
	cin>>n;
	vector<pii>v(n);
	for(int i=0; i<n; ++i){
		cin>>a>>b;
		v[i] = make_pair(a,b);
	}
	sort(v.begin(), v.end(), cmp);
	for(int i=0; i<n; ++i)
		cout<<v[i].first<<" "<<v[i].second<<'\n';
	return 0;
}
