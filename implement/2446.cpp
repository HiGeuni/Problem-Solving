#include<iostream>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	int n;
	cin>>n;
	for(int i=n; i>0; --i){
		for(int j=0; j<n-i; ++j)
			cout<<" ";
		for(int j=0; j<2*i-1; ++j)
			cout<<'*';
		cout<<endl;
	}
	
	for(int i=1; i<n; ++i){
		for(int j=n-i-1; j>0; --j)
			cout<<" ";
		for(int j=0; j<2*i+1; ++j)
			cout<<"*";
		cout<<endl;
	}
	return 0;
}
