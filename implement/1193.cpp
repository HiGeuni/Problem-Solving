//1193 분수찾기

#include<bits/stdc++.h>
using namespace std;

int main(){
	int i, n,up,down, sum =0;
	cin>>n;
	for(i=1; i<=n; ++i){
		sum+=i;
		if(n<=sum)
			break;
	}
	if(i %2 ==0){
		down = sum-n+1;
		up = i +1 -down;
	}
	else{
		up = sum - n +1;
		down = i+1 -up;
	}
	cout<<up<<"/"<<down<<endl;
	return 0;
}
