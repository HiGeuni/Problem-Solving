#include<bits/stdc++.h>
using namespace std;

int main(){
	long long n, m, init = 0, max_ = 0;
	scanf("%lld%lld", &n, &m);
	vector<int>v(n);
	for(int i=0; i<n; ++i){
		cin>>v[i];
		if(i < m)
			init += v[i];
	}
	max_ = init;
	for(int i=0; i<n-m; ++i){
		init -= v[i];
		init += v[i + m];
		max_ = max(max_, init);
	}
	printf("%lld\n", max_);
	return 0;
}
