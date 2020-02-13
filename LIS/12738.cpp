//12738 가장 긴 증가하는 수열 3

#include<bits/stdc++.h>
using namespace std;

int main(){
	cin.tie();
	int n, tmp, res =0;
	cin>>n;
	vector<int>ans;
	ans.push_back(-2e9);
	for (int i=0; i<n; ++i){
		cin>>tmp;
		if(ans.back() <tmp){
			ans.push_back(tmp);
			res++;
		}
		else{
			auto it = lower_bound(ans.begin(), ans.end(), tmp);
			*it =x;
		}
	}
	cout<<res;
	return 0;
}
