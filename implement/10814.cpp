//10814 나이순 정렬
//20200221
//stable sort

#include<bits/stdc++.h>
using namespace std;
typedef pair<int, string> pis;

bool cmp(pis a, pis b){
	return a.first < b.first;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n,a;
	string b;
	cin>>n;
	vector<pis>v(n);
	for(int i=0; i<n; ++i){
		cin>>a>>b;
		v[i] = make_pair(a,b);
	}
	stable_sort(v.begin(), v.end(), cmp);
	for(int i=0; i<n; ++i)
		cout<<v[i].first<<" "<<v[i].second<<'\n';
	return 0;
}
