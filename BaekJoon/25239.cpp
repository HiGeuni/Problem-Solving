#include<bits/stdc++.h>
using namespace std;

int curH, curM;
vector<int>h(6);

// init time
void initTime(string s){
	int tmp = 0;
	for(int i=0; i<s.size(); ++i){
		if(s[i] == ':'){
			curH = tmp;
			tmp = 0;
			continue;
		}
		tmp *= 10;
		tmp += s[i] - '0';
	}
	curM = tmp;
}

// get region
int getRegion(){
	return curH / 2;
}

// s.T

//time calcultation, return region
void calc(string t){
	if(t == "^"){
		int t = getRegion();
		h[t] = 0;
	}else if(t == "10MIN"){
		curM += 10;
	}else if(t == "30MIN"){
		curM += 30;
	}else if(t == "50MIN"){
		curM += 50;
	}else if(t == "2HOUR"){
		curH += 2;
	}else if(t == "4HOUR"){
		curH += 4;
	}else if(t == "9HOUR"){
		curH += 9;
	}
	if(curM >= 60){
		curM-= 60;
		curH += 1;
	}
	if(curH >= 12){
		curH -= 12;
	}
}

int main(){
	int numCmd;
	string s, cmd, _time;
	cin>>s;
	initTime(s);
	for(int i=0; i<6; ++i)
		cin>>h[i];
	cin>>numCmd;
	for(int i=0; i<numCmd; ++i){
		cin>>cmd>>_time;
		calc(_time);
	}
	int ans = 0;
	for(int i=0; i<6; ++i){
		ans += h[i];
	}
	cout<<((ans >= 100)?100:ans)<<endl;
	return 0;
}
