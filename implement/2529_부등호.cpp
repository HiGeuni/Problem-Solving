#include<bits/stdc++.h>
using namespace std;

vector<int>max_, min_;
string s;

bool solve(vector<int>&v){
	for(int i=0; i<s.size(); i++){
		if(s[i] == '<' && v[i]>v[i+1]) return false;
		else if(s[i] == '>' && v[i]<v[i+1]) return false;
	}
	return true;
}

int main(){
	int N;
	char tmp;
	cin>>N;
	for(int i=0; i<N; i++){
		cin>>tmp;
		s.push_back(tmp);
	}
	for(int i=9; i>=9-(N+1); i--){
		max_.push_back(i);
	}
	while(1){
		if(solve(max_)) break;
		prev_permutation(max_.begin(), max_.end());
	}
	for(int i=0; i<N+1; i++){
		min_.push_back(i);
	}
	while(1){
		if(solve(min_)) break;
		next_permutation(min_.begin(), min_.end());
	}
	for(int i=0; i<N+1; i++)
		cout<<max_[i];
	cout<<endl;
	for(int i=0; i<N+1; i++)
		cout<<min_[i];
	
}
