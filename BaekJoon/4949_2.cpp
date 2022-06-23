#include<bits/stdc++.h>
using namespace std;

int main(){
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	while(true){
		stack<char>st;
		bool flag = true;
		string s;
		getline(cin, s);
		if(s.size() == 1 && s[0] == '.')
			break;
		for(int i=0; i<s.size(); ++i){
			if(s[i] == '(' || s[i] == '['){
				st.push(s[i]);
			}else if(s[i] == ')'){
				if(st.size() != 0 && st.top() == '(') st.pop();
				else{
					flag = false;
					break;
				}
			}else if(s[i] == ']'){
				if(st.size() != 0 && st.top() == '[') st.pop();
				else{
					flag = false;
					break;
				}
			}
		}
		if(st.empty() && flag)
			cout<< "yes"<<'\n';
		else
			cout<< "no"<<'\n';
	}
	return 0;
}
