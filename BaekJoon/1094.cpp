#include<iostream>
using namespace std;

int main(){
	int rsv = 64;
	int base =64;
	int x;
	int cnt =0;
	cin>>x;
	while(x!=0){
		if(x<rsv){		
			base/=2;
			if(x>=rsv-base){
				x-=base;
				rsv-=base;
				cnt++;
			}
			else{
				rsv-=base;
			}
		}
		else if(x == rsv){
			cnt++;
			break;
		}
	}
	cout<<cnt;
}	
