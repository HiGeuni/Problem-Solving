#include<bits/stdc++.h>

using namespace std;

vector<int>v;

int main(){
	int sum = 0, N;
	cin>>N;
	v.resize(N);
	for(int i=0; i<N; i++)
	{
		cin>>v[i];
	}
	sort(v.begin(), v.end());
	for(int i=0; i<N; i++){
		sum+= v[i] *(N-i);
	}
	cout<<sum;
	return 0;
}
