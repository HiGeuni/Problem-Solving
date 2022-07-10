#include<bits/stdc++.h>
using namespace std;

int arr[2200][2200];
int res[3];

void func(int n, int y, int x){
	int color = arr[y][x];
	for(int i=x; i<x+n; ++i){
		for(int j=y; j<y+n; ++j){
			if(color != arr[j][i]){
				func(n/3, y, x);
				func(n/3, y+n/3, x);
				func(n/3, y+(2*n)/3, x);
				func(n/3, y, x+n/3);
				func(n/3, y+n/3, x+n/3);
				func(n/3, y+(2*n)/3, x+n/3);
				func(n/3, y, x+(2*n)/3);
				func(n/3, y+n/3, x+(2*n)/3);
				func(n/3, y+(2*n)/3, x+(2*n)/3);
				return;
			}
		}
	}
	res[color+1]++;
}

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
	for(int i=0; i<n; ++i){
		for(int j=0; j<n; ++j){
			cin>>arr[j][i];
		}
	}
	func(n, 0, 0);
	for(int i=0; i<3; ++i){
		cout<<res[i]<<'\n';
	}
}
