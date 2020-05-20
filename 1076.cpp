#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

int main(){
	string col[10] ={"black", "brown", "red", "orange", "yellow", "green", "blue", "violet", "grey", "white"}; 
	string str;
	long long num[10], res;
	int tmp =1;
	int mem[3];
	for(int i=0; i<10; i++){
		num[i] = tmp;
		tmp*=10;
	}
	for(int i=0; i<3; i++){
		cin>>str;
		for(int j=0; j<10; j++){
			if(str == col[j])mem[i] = j;
		}
	}
	res = (mem[0]*10+mem[1])*num[mem[2]];
	
	printf("%lld", res);
	return 0;
}
