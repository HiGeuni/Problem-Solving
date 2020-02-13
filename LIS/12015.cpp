//12015 가장 긴 증가하는 수열2 

#include<bits/stdc++.h>
using namespace std;

vector<int> LIS(vector<int> &v){
	vector<int>ans(1,0);
	for(int i =0 ;i<v.size(); ++i){
		if(v[i] > ans.back()){
			ans.push_back(v[i]);
		}
		else{
			vector<int>::iterator it = lower_bound(ans.begin(), ans.end(), v[i]);
			*it = v[i];
		}
	}
	return ans;
}

int main(){
	int n;
	cin>>n;
	vector<int>v(n);
	for(int i=0; i<n; ++i)
		cin>>v[i];
	vector<int>ans = LIS(v);
	cout<<ans.size()-1;
	return 0;
}
