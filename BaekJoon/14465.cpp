#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	int n, k, b, ta;
	cin>>n>>k>>b;
	vector<bool>is_break(n+1, false);
	for(int i=0; i<b; ++i){
		cin>>ta;
		is_break[ta] = true;
	}

	int a = 0;
	for(int i=1; i<=k; ++i){
		if(is_break[i]) a += 1;
	}
	int ans = a;
	for(int i=2; i<=n-k+1; ++i){
		if(is_break[i-1]){
			a -= 1;
		}
		if(is_break[i+k-1]){
			a += 1;
		}
        
		ans = min(ans, a);
	}
    cout<<ans<<'\n';
	return 0;
}
