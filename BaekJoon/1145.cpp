#include<iostream>
#include<vector>
#include<utility>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<tuple>
#include<algorithm>
using namespace std;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int tmp;
	vector<int>num;
	for(int i=0; i<5; i++){
		cin>>tmp;
		num.push_back(tmp);
	}
	sort(num.begin(), num.end());
	int s=num[0];
	while(1){
		int cnt =0;
		for(int i=0; i<5; i++){
			if(s%num[i] == 0)
				cnt++;
			
		}
		if(cnt>=3)break;
		else s++;
	}
	cout<<s;
	return 0;
}
