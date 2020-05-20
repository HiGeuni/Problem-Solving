#include<bits/stdc++.h>
using namespace std;

int main(){
	char vowel[10] = {'a', 'e', 'i','o','u', 'A', 'E', 'I', 'O', 'U'};
	int cnt, len;
	string str;
	for(;;){
		cnt =0;
		getline(cin, str);
		if (str[0] == '#') return 0;
		for(int i=0; i<str.length(); ++i){
			for(int j=0; j<10; ++j){
				if(str[i] == vowel[j]){
					cnt++;
					break;
				}
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
