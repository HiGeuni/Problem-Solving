#include<bits/stdc++.h>
using namespace std;

typedef struct person{
	int weight;
	int height;
}Person;

int main(){
	Person P[51];
	int n;
	cin>>n;
	for(int i=0; i<n; i++)
		cin>>P[i].weight>>P[i].height;
	for(int i=0; i<n; i++){
		int cnt =0;
		for(int j=0; j<n; j++){
			if(P[i].weight < P[j].weight && P[i].height < P[j].height)
				cnt++;
		}
		cout<<cnt+1<<" ";
	}
	return 0;
}
