#include<bits/stdc++.h>
using namespace std;


int main(){
	int arr[3][100001];
	int min_ans[3][2];
	int max_ans[3][2];
	int N;
	cin.tie();
	cin>>N;
	for(int i = 0; i<N; i++)
		for(int j=0; j<3; j++)
			cin>>arr[j][i];
	min_ans[0][0] = max_ans[0][0] = arr[0][0];
	min_ans[1][0] = max_ans[1][0] = arr[1][0];
	min_ans[2][0] = max_ans[2][0] = arr[2][0];
	
	for(int i=1; i<N; i++){
		max_ans[0][1] = arr[0][i]+max(max_ans[0][0], max_ans[1][0]);
		max_ans[1][1] = arr[1][i]+max(max(max_ans[0][0], max_ans[1][0]), max_ans[2][0]);
		max_ans[2][1] = arr[2][i] + max(max_ans[1][0], max_ans[2][0]);
		
		max_ans[0][0] = max_ans[0][1];
		max_ans[1][0] = max_ans[1][1];
		max_ans[2][0] = max_ans[2][1];
		
		min_ans[0][1] = arr[0][i]+min(min_ans[0][0], min_ans[1][0]);
		min_ans[1][1] = arr[1][i]+min(min(min_ans[0][0], min_ans[1][0]), min_ans[2][0]);
		min_ans[2][1] = arr[2][i] + min(min_ans[1][0], min_ans[2][0]);
		
		min_ans[0][0] = min_ans[0][1];
		min_ans[1][0] = min_ans[1][1];
		min_ans[2][0] = min_ans[2][1];
		
	}
	cout<<max(max(max_ans[0][0], max_ans[1][0]), max_ans[2][0])<<" ";
	cout<<min(min(min_ans[0][0], min_ans[1][0]), min_ans[2][0]);
	return 0;
	
}
