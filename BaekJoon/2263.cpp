#include<bits/stdc++.h>
using namespace std;

vector<int>in_, post_;

void dnq(int l, int r, int pl, int pr){
	if( l > r || pl > pr) return;
	int root_ = post_[pr];
	int t = in_[root_];
	cout << root_<<" ";
	dnq(l, t-1, pl, pl + (t-1-l));
	dnq(t+1, r, pl+t-l, pr-1);
}

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, t;
	cin>>n;
	in_.resize(n+1);
	post_.resize(n+1);
	for(int i=0; i<n; ++i){
		cin>>t;
		in_[t] = i;
	}
		
	for(int i=0; i<n; ++i)
		cin>>post_[i];
	
	dnq(0, n-1, 0, n-1);
	return 0;
}
