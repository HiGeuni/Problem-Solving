//12738 가장 긴 증가하는 수열 3

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int>v(n);
	for(int i=0; i<n; ++i)
		cin>>v[i];
	vector<int>ans(1,-2e9);
	for(int num : v){
		if(num > ans.back())
			ans.push_back(num);
		else{
			vector<int>::iterator it = lower_bound(ans.begin(), ans.end(), num);
			*it = num;
		}
	}
	cout<<ans.size()-1;
	return 0;
}
