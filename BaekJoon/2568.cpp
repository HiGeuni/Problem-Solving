#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;

bool comp(const pii &a, const pii &b)
{
	return a.second < b.second;
}

int main(void)
{
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int ta, tb, n;
	cin>>n;
	vector<pii> v;
	for(int i=0; i<n; ++i){
		cin>>ta>>tb;
		v.push_back(make_pair(ta, tb));
	}
	sort(v.begin(), v.end());

	vector<pii>dp;
	vector<int>idx;
	for(int i=0; i<n; ++i){
		if(dp.size() == 0){
			dp.push_back(v[i]);
			idx.push_back(0);
		}else{
			if(dp.back().second >= v[i].second){
				auto iter = lower_bound(dp.begin(), dp.end(), v[i], comp) - dp.begin();
				dp[iter] = v[i];
				idx.push_back(iter);
			}
			else{
				dp.push_back(v[i]);
				idx.push_back(dp.size()-1);
			}
		}
	}
	int cur = dp.size()-1;
	cout<<v.size() - cur - 1<<'\n';
	vector<int> ans;
	for(int i=idx.size()-1; i>=0; --i){
		if(cur == idx[i]) cur -= 1;
		else{
			ans.push_back(v[i].first);
		}
	}
	reverse(ans.begin(), ans.end());
	for(auto a : ans){
		cout<<a<<'\n';
	}

	return 0;
}
