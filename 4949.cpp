//4949 균형잡힌 세상
//20200228
//). 와 같은 경우를 생각하지 못함.

#include<bits/stdc++.h>
using namespace std;

stack<char>st;

int main(){
	int right = 0;
    cin.tie(0);
    ios::sync_with_stdio(0);
	string str;
	while(1){
		right = 0;
		if(!st.empty())
			while(!st.empty())
				st.pop();
		getline(cin, str);
		if(str.size()== 1 && str[0] == '.')
			break;
		int len = str.length();
		for(int i=0; i<len; ++i){
			if(str[i] == '.' && i == len-1)
				break;
			if(str[i] == '[' || str[i] == '(')
				st.push(str[i]);
			if(str[i] == ']'){
				right ++;
				if(!st.empty() && st.top() == '['){
					st.pop();
					right--;
				}
			}
			if(str[i] == ')'){
				right ++;
				if(!st.empty() && st.top() == '('){
					st.pop();
					right --;
				}
		}
		}
		if(st.empty()&& right == 0)
			cout<<"yes"<<endl;
		else{
			cout<<"no"<<endl;
		}
	}
	return 0;
}
