#include<bits/stdc++.h>
using namespace std;

int main(){
	cin.tie();
	ios_base::sync_with_stdio(0);
	int arr[10001];
	int n, tmp;
	memset(arr, 0, sizeof(arr));
	cin>>n;
	for(int i=0; i<n; ++i){
		cin>>tmp;
		arr[tmp]++;
	}
	for(int i=1; i<10001; i++){
		for(int j=0; j<arr[i]; ++j){
			cout<<i<<'\n';
		}
	}
	return 0;
}
