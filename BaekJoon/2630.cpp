#include<bits/stdc++.h>
using namespace std;

int arr[129][129];
int ans[2] = {0,0};

void func(int n, int x, int y){
	if(arr[y][x] <0) return;
	int color = arr[y][x];
	for(int i=x; i<x+n; ++i){
		for(int j=y; j<y+n; ++j){
			if(color != arr[j][i]){
				func(n/2, x, y);
				func(n/2, x+n/2, y);
				func(n/2, x, y+n/2);
				func(n/2, x+n/2, y+n/2);
				return;
			}
		}
	}
	ans[color]++;
}

int main(){
	cin.tie();
	ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
	memset(arr, -1, sizeof(arr));
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			cin>>arr[j][i];
		}
	}
	func(n, 0, 0);
	for(int i=0; i<2; ++i)
		cout<<ans[i]<<endl;
	return 0;
}
