//1448 삼각형 만들기
//2020-02-17

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, sum= -1;
	cin>>n;
	vector<int>vi(n);
	for(int i=0; i<n; ++i)
		cin>>vi[i];
	sort(vi.begin(), vi.end(), greater<int>());
	for(int i=0; i<n-2; ++i){
		if(vi[i]<vi[i+1] + vi[i+2]){
			sum = vi[i] + vi[i+1] + vi[i+2];
			break;
		}
	}
	cout<<sum;
	return 0;
}
