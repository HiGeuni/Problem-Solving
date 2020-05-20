#include<bits/stdc++.h>
using namespace std;

int main(){
	bool flag= false;
	vector<int>nan;
	int tmp, sum=0;
	for(int i=0; i<9; i++){
		cin>>tmp;
		nan.push_back(tmp);
		sum+=tmp;
	}
	sort(nan.begin(),nan.end());
	for(int i=0; i<9; i++){
		for(int j=i+1; j<9; j++){
			if(sum-nan[i]-nan[j]==100){
				flag = 1;
				for(int k=0; k<9; k++){
					if(k!=i && k!=j)
						cout<<nan[k]<<endl;
				}
				if(flag) break;
			}
		}
		if(flag) break;
	}
	return 0;
}
