//1057 토너먼트
#include<bits/stdc++.h>
using namespace std;

bool is_fight(int a, int b){
	if(a>b) { 
		int tmp = a;
		a =b;
		b =tmp;
	}
	if(b%2 == 0&& (b-a)==1) return true;
	return false;
}

int main(){
	int num, kim, lim, cnt =1;
	cin>>num>>kim>>lim;
	while(num!=1){
		if(is_fight(kim, lim)) break;
		kim = (kim+1)/2;
		lim = (lim+1)/2;
		cnt++;
	}
	cout<<cnt;
}
