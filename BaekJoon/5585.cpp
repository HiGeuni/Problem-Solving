#include<iostream>
using namespace std;

int main(){
	int charge[6] = {500,100,50,10,5,1};
	int n, cnt =0;
	cin>>n;
	n = 1000-n;
	while(n!=0){
		for(int i=0; i<6; i++){
			if(n>=charge[i])
			{
				n-=charge[i];
				cnt++;
				break;
			}
		}
	}
	cout<<cnt;
	return 0;
}
