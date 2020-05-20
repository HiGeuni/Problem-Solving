#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int num, prc, cnt=0, tmp;
	cin>>num>>prc;
	vector<int>v;
	for(int i=0; i<num; i++){ cin>>tmp; v.push_back(tmp);}
	sort(v.begin(), v.end());
	while(prc!=0){
		for(int i = v.size()-1; i>=0; i--){
			if(prc>=v[i]){
				prc-=v[i];
				cnt++;
				break;
			}
		}
	}
	cout<<cnt;
	return 0;
}
