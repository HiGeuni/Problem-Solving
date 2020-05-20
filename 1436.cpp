//1436 영화감독 숌

#include<bits/stdc++.h>
using namespace std;

int main(){
	int num = 665, n, tmp, cnt=0;
	bool flag;
	cin>>n;
	while(++num){
		tmp =num;
		flag = false;
		while(tmp){
			if(tmp % 1000 == 666)
				flag = true;
			tmp/=10;
		}
		if(flag){
			cnt++;
			if(cnt == n) break;
		}
	}
	cout<<num;
	return 0;
}
