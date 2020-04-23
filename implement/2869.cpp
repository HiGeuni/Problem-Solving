#include<stdio.h>

int main() {
	int A, B, V, Day_Distance, Last_Point, cnt = 0;
	scanf("%d%d%d", &A, &B, &V);
	Day_Distance = A - B;
	Last_Point = V - A;
	for (Last_Point; Last_Point < V; Last_Point++) {
		if (Last_Point%Day_Distance==0) {
			cnt = Last_Point/ Day_Distance;
			break;
		}
	}

	printf("%d", cnt+1);
	return 0;
}
