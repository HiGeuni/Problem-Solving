#include<bits/stdc++.h>
using namespace std;

bool prime[100001];

int main(){
	int from, to, sum =0, min_val = 1000000;
	prime[0] = prime[1] = true;
	for(int i=2; i*i<=10001; ++i){
		for(int j=2; j*i<=10001; ++j){
			prime[i*j] = true;
		}
	}
	cin>>from>>to;
	for(int i=from; i<=to; ++i){
		if(!prime[i]){
			min_val = min(i, min_val);
			sum+=i;
		}
	}
	if(min_val == 1000000){
		cout<<-1;
		return 0;
	}
	cout<<sum<<endl;
	cout<<min_val;
	return 0;
}
