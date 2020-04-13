#include<iostream>

using namespace std;

int main(){
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int B[4];int A[4], flag;
	A[3] =0; B[3] =0;
	for(int i=0; i<3; i++){
		cin>>A[i];
		A[3]+=(A[i]*(3-i));
	}
	for(int i=0; i<3; i++){
		cin>>B[i];
		B[3]+=(B[i]*(3-i));
	}
	A[3]>B[3]?flag =0:flag =1;
	if(flag == 1){
		A[3] == B[3]?flag =2:flag = 1;
	} 
	switch(flag){
		case 0:
			cout<<"A";
			break;
		case 1:
			cout<<"B";
			break;
		case 2:
			cout<<"T";
			break;
	}
	return 0;
}
