#include<bits/stdc++.h>
using namespace std;

int main(){
	float a, b;
	cin>>a>>b;
	cout<<((a - (a * b / 100) >= 100)? 0 : 1);
	return 0;
}
