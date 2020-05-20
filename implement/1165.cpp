//1165 좌표 정렬하기
//20200221

#include<bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

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
	sort(v.begin(), v.end());
	for(int i=0; i<n; ++i)
		cout<<v[i].first<<" "<<v[i].second<<'\n';
	return 0;
}
