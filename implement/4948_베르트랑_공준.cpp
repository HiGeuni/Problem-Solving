#include<bits/stdc++.h>
using namespace std;

bool prime[300001];

int main(){
	cin.tie();
	ios_base::sync_with_stdio(0);
	int n, cnt;
	prime[0] = prime[1] = true;
	for(int i=2; i*i<=300000; ++i){
		for(int j=2; j*i<=300000; ++j){
			prime[i*j] = true;
		}
	}
	while(1){
		cnt =0;
		cin>>n;
		if(n==0)break;
		for(int i=n+1;i<2*n+1; i++)
			if(!prime[i]) cnt++;
		cout<<cnt<<endl;
	}
	return 0;
}
