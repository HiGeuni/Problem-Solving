//1297 TV 크기

#include<bits/stdc++.h>
using namespace std;

int main(){
	int diagonal,h, w, th, tw;
	cin>>diagonal>>h>>w;
	double r = diagonal / (sqrt(pow(h,2) + pow(w,2)));
	tw = w * r;
	th = h * r;
	printf("%d %d\n",th,tw);
	return 0;
}
