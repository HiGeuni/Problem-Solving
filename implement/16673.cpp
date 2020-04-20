//166733 고려대힉교에는 공식 와인이 있다.
//20040420

#include <iostream>
#include<cmath>
using namespace std;

int main() {
	int C, K, P;
	cin>>C>>K>>P;
	int ans = 0;
	for(int i=1; i<=C; ++i){
		ans += K*i+pow(i,2)*P;
	}
	cout<<ans;
	return 0;
}
