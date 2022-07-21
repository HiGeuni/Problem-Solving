// 고려해야 하는 것
// S와 L을 동시에 생각해야 함.
// n : k개의 ~~~ logn : 이분 탐색
// 유통기한 
#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;

typedef long long ll;
typedef pair<ll,int> pli;

int K, G;
vector<pli>important;
vector<pli>not_important;

bool decision(int day){
	ll num_germ = 0;
	for(int i=0; i<important.size(); ++i){
		num_germ += (important[i].x * max(1, day-important[i].y));
	}
	priority_queue<ll, vector<ll>, greater<ll>> pq;
	for(int i=0; i<not_important.size(); ++i){
		pq.push(not_important[i].x * max(1, day-not_important[i].y));
	}

	for(int i=0; i<int(not_important.size()) - K; ++i){
		num_germ += pq.top();
		pq.pop();
	}
	if(num_germ <= G){
		return true;
	}else{
		return false;
	}
}

int main(){
	int N, S, L, O;
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin>>N>>G>>K;
	for(int i=0; i<N; ++i){
		cin>>S>>L>>O;
		(O == 0)? important.emplace_back(S, L) : not_important.emplace_back(S, L);
	}
	ll l = 0, r = 2e9;
	while(l <= r){
		ll mid = (l+r)/2;
		if(decision(mid)){
			l = mid + 1;
		}else{
			r = mid - 1;
		}
	}
	cout<<r;
	return 0;
}
