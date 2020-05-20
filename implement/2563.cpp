#2563 
#20200424


#include<iostream>
using namespace std;

int arr[101][101];

int main(){
	int cnt =0;
	int tx, ty;
	int n;
	cin>>n;
	for(int i=0; i<n; ++i){
		cin>>tx>>ty;
		for(int j=0; j<10; ++j){
			for(int k=0; k<10; ++k){
				if(arr[tx+j][ty+k] == 0){
					cnt+=1;
					arr[tx+j][ty+k] = 1;
				}
			}
		}
	}
	cout<<cnt;
	return 0;
}
