//1292 쉽게 푸는 문제 using prefix sum

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, m, idx=1;
	int psum[1100];
	cin>>n>>m;
	psum[0] = 0;
	for(int i=1; i<46; ++i){
		for(int j=1; j<=i; ++j){
			psum[idx] = psum[idx-1]+i;
			idx++;
		}
	}
	cout<<psum[m] - psum[n-1];
	return 0;
}
