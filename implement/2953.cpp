//2953 나는 요리사다
//20200221

#include<bits/stdc++.h>
using namespace std;

int main(){
	int score[4], ans = 0, tmp, num;
	for(int i=0; i<5; ++i){
		tmp =0;
		for(int j=0; j<4; ++j){
			cin>>score[j];
			tmp+=score[j];
		}
		if(ans <tmp){
			num = i+1;
			ans = tmp;
		}
	}
	cout<<num<<" "<<ans<<endl;
	return 0;
}

