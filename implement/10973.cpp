#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	bool flag = true;
	cin>>n;
	vector<int>v(n);
	for(int i=0; i<n; ++i)
		cin>>v[i];
	for(int i=0; i<n; ++i){
		if(v[i] == i+1)
			continue;
		else{
			flag = false;
		}
	}
	if(flag){
		cout<<-1;
		return 0;
	}
	prev_permutation(v.begin(), v.end());
	for(int i=0; i<n; ++i)
		cout<<v[i]<<" ";
	return 0;
	
}
