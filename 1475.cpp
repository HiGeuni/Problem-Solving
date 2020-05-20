//1475 방번호
//2020-02-17

#include<bits/stdc++.h>
using namespace std;

int main(){
	//resv number
	int arr[10] = {0,};
	int n, res =1;
	cin>>n;
	//initialization
	while(n!=0){
		arr[n%10]++;
		n/=10;
	}
	//find max_number in array
	for(int i=0; i<10; ++i){
		//except 6 and 9
		if(i==6 || i==9)
			continue;
		res = max(res, arr[i]);
	}
	res = max(res, (arr[6]+arr[9]+1)/2);
	cout<<res;
	return 0;	
}
