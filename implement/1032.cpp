#include<iostream>
#include<cstring>

using namespace std;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
	string s;
	cin>>s;
	for(int i=0; i<n-1; i++){
		string tmp;
		cin>>tmp;
		for(int j=0; j<s.size(); j++){
			if(s[j]!=tmp[j]){
				s[j] = '?';
			}
		}
	}
	cout<<s;
	return 0;
}
