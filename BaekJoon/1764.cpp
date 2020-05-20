#include<bits/stdc++.h>
using namespace std;

int main(){
	vector<string>v, v2, ans;
	string tmp;
	int n, m, cnt =0;
	cin>>n>>m;
	cin.tie();
	ios_base::sync_with_stdio();
	for(int i=0; i<n; ++i){
		cin>>tmp;
		v.push_back(tmp);	
	}
	for(int i=0; i<m; ++i){
		cin>>tmp;
		v2.push_back(tmp);
	}
	sort(v2.begin(), v2.end());
	for(int i=0; i<v.size(); ++i){
		if(binary_search(v2.begin(), v2.end(), v[i])){
			cnt++;
			ans.push_back(v[i]);
		}

	}
	cout<<cnt<<'\n';
	sort(ans.begin(), ans.end());
	
	for(int i=0; i<ans.size(); ++i)
		cout<<ans[i]<<'\n';
	return 0;
}
