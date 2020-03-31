#include<bits/stdc++.h>
int main(){
	int arr[9], idx, big = -2e9;
	for(int i=0; i<9; i++){
		scanf("%d", &arr[i]);
		if(big<arr[i]){
			idx = i+1;
			big = arr[i];
		}
	}
	printf("%d\n%d", big, idx);
	return 0;
}
