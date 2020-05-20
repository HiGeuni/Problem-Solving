#include<iostream>

using namespace std;
char arr[8][8];
int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int cnt=0;
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			cin>>arr[j][i];
		}
	}
	for(int i=0; i<8; i++){
		if(i%2 == 1){
			for(int j=1; j<8; j+=2){
				if(arr[j][i]== 'F')cnt++; 
			}
		}
		else{
			for(int j=0; j<8; j+=2){
				if(arr[j][i]== 'F')cnt++;
			}
		}
	}
	cout<<cnt;
	return 0;
}
