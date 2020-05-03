#include<iostream>
#include<vector>
#include<utility>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<tuple>
#include<algorithm>
using namespace std;
int mem[100000];
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int num, tmp, res;
	cin>>num;
	vector<int>real;
	for(int i=0; i<num; i++){
		cin>>tmp;
		real.push_back(tmp);
	}
	sort(real.begin(), real.end());
	res = real[0] * real[num-1];
	cout<<res;
	return 0;
}
