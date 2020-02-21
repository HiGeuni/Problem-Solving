//2108 통계학
//20200221
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, res[3], v_mode=-10, v_sum=0;
	cin>>n;
	vector<int>v(n, 0);
	vector<int>mode(8010, 0);
	for(int i=0; i<n; ++i){
		cin>>v[i];
		v_sum += v[i];
		mode[v[i]+4000]++;
	}
	sort(v.begin(), v.end());
	//median
	res[0] = v[n/2];
	//mode
	bool flag = false;
	for(int i=0; i<=8005; ++i){
		if(v_mode < mode[i]){
			v_mode = mode[i];
			res[1] = i;
			flag = false;
		}
		else if(v_mode == mode[i] && !flag){
			res[1] = i;
			flag = true;
		}
	}
	res[1] -= 4000;
	//max - min
	res[2] = v[n-1] - v[0];
  //arithmetic mean
	printf("%.0f\n", (double)v_sum/n);
	for(int i=0; i<3; ++i)
		cout<<res[i]<<endl;
	return 0;
}
