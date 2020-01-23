#include<bits/stdc++.h>
using namespace std;

#define INF 2e9

int main(){
	int n,x, ans =0;
	vector<int>v;
	v.push_back(-INF);
	cin>>n;
	for(int i=0; i<n; i++){
		scanf("%d", &x);
		if(v.back() <x){
			v.push_back(x);
			ans++;
		}
		else{
			auto it = lower_bound(v.begin(), v.end(), x);
			*it =x;
		}
	}
	cout<<ans;
}
