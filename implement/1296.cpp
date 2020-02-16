//1296 데이트

#include<bits/stdc++.h>
using namespace std;

int main(){
	string oh, tmp, ans_girl;
	int arr[4];//arr[0][0] : 0번째 여자의 L 개수
	int ohman[4]= {0,};
	int n;
	int ans = -1;
	int num_L, num_O, num_V, num_E;
	int res;
	cin>>oh;
	for(int i=0; i<oh.size(); ++i){
		switch(oh[i]){
			case 'L':
				ohman[0]++;
				break;
			case 'O':
				ohman[1]++;
				break;
			case 'V':
				ohman[2]++;
				break;
			case 'E':
				ohman[3]++;
				break;
		}
	}
	cin>>n;
	for(int i=0; i<n; ++i){
		//initialization
		for(int j=0; j<4; ++j)
			arr[j] =0;
		//input girl
		cin>>tmp;
		//num_L, num_O, num_V, num_E
		for(int j=0; j<tmp.size(); ++j){
			switch(tmp[j]){
				case 'L':
					arr[0]++;
					break;
				case 'O':
					arr[1]++;
					break;
				case 'V':
					arr[2]++;
					break;
				case 'E':
					arr[3]++;
					break;
			}
		}
		num_L = arr[0] + ohman[0];
		num_O = arr[1] + ohman[1];
		num_V = arr[2] + ohman[2];
		num_E = arr[3] + ohman[3];
		res = (num_L + num_O) * (num_L + num_V) * (num_L + num_E)*(num_O + num_V)*(num_O + num_E)*(num_V + num_E);
		res%=100;
		
		if(res > ans){
			ans = res;
			ans_girl = tmp;
		}
		if(res == ans){
			if(ans_girl > tmp){
				ans_girl = tmp;
			}
		}
	}
	cout<<ans_girl;
	return 0;
}
