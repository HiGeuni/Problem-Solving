#include<iostream>
#include<string>
using namespace std;

int main(){
	string s;
	string tmp ="";
	bool sum = true;
	int res =0;
	cin>>s;
	for(int i=0; i<=s.length(); ++i){
		if(s[i]=='+' || s[i] == '-'  ||  s[i]=='\0'){
			
			if(sum){
				res += stoi(tmp);
			}
			else{
				res -= stoi(tmp);
			}
			if(s[i] == '-')
				sum = false;
			tmp = "";
			continue;
		}
		tmp+=s[i];
	}
	cout<<res;
	return 0;
}
