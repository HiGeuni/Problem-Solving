#include<bits/stdc++.h>
using namespace std;

int main(){
	string s;
	int sum =0;
	cin>>s;
	for(int i=0; i<s.size(); i++){
		sum+=s[i]-'0';
	}
	sort(s.begin(), s.end());
	if(sum%3!=0||s[0]!='0'){
		cout<<-1<<endl;
		return 0;
	}
	for(int i=0; i<s.size(); i++){
		cout<<s[s.size()-i-1];
	}
	return 0;
}
