//1021 회전하는 큐
#include<iostream>
#include<queue>
using namespace std;

int main(){
	deque<int>dq;
	int n, tmp, m, idx, cnt =0;
	cin>>n>>m;
	for(int i=0; i<n; ++i){
		dq.push_back(i+1);
	}
	for(int i=0; i<m; ++i){
		cin>>tmp;
		for(int j=0; j<n; ++j){
			if(dq[j] == tmp){
				idx = j;
				break;
			}
		}
		if(idx < dq.size() - idx){
			while(1){
				if(dq.front() == tmp){
					dq.pop_front();
					break;
				}
				dq.push_back(dq.front());
				dq.pop_front();
				cnt++;
			}
		}
		else{
			while(1){
				if(dq.front() == tmp){
					dq.pop_front();
					break;
				}
				dq.push_front(dq.back());
				dq.pop_back();
				cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
