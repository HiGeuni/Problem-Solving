#include<bits/stdc++.h>
using namespace std;

bool prime[10010];

int main(){
	cin.tie();
	ios_base::sync_with_stdio();
	int tc, n, num1, num2, con;
	prime[0] = prime[1] = true;
	for(int i=2; i*i<=10001; ++i){
		for(int j=2; j*i<=10001; ++j){
			prime[i*j] = true;
		}
	}
	cin>>tc;
	for(int i=0; i<tc; ++i){
		cin>>n;
		con = sqrt(n);
		for(int j=con; j<=n-con; ++j){
			if(j>n-j) break;
			if(!prime[j]&&!prime[n-j]){
				num1 = j;
				num2 = n-j;
			}
		}
		cout<<num1<<" "<<num2<<endl;
	}
	return 0;
}
