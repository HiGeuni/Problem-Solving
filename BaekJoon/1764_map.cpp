#include<iostream>
#include<map>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	cin.tie();
	ios_base::sync_with_stdio();
	vector<string>vs;
	string tmp;
	int n, m, ans =0;
	cin>>n>>m;
	map<string, int> msi;
	for(int i=0; i<n; ++i){
		cin>>tmp;
		msi[tmp] = 1;
	}
	map<string,int>::iterator it;
	for(int j=0; j<m; ++j){
		cin>>tmp;
		if(msi.find(tmp) != msi.end()){
			vs.push_back(tmp);
			ans ++;
		}
	}
	sort(vs.begin(), vs.end());
	cout<<ans<<endl;
	for(int i=0; i<ans; ++i){
		cout<<vs[i]<<endl;
	}
	return 0;
}
