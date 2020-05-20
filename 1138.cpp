//1138 줄 세우기
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int>v(n), ans(n, -1);
	for(int i=0; i<n; ++i)
		cin>>v[i];
	for(int i=0; i<n; ++i){
		int cnt =0;
		for(int j=0; j<n; ++j){
			if(cnt == v[i]){
				if(ans[j] == -1){
					ans[j] = i+1;
					break;
				}
			}
			if(ans[j] == -1)
				cnt ++;
		}
	}
	for(int i=0; i<n; ++i){
		cout<<ans[i]<<" ";
	}
	return 0;
}
