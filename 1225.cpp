#include<iostream>
#include<cstring>
using namespace std;
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	long long ans = 0;
	string a,b;
	cin>>a>>b;
	for(int i=0; i<a.size(); i++){
		for(int j=0; j<b.size(); j++){
			ans += (a[i]-'0')*(b[j]-'0');
		}
	}
	cout<<ans;
	return 0;
}
