#include<stdio.h>

int main() {
	int Case, H, W, N, room_H, room_W;
	scanf("%d", &Case);
	for (int i = 0; i < Case; i++) {
		scanf("%d%d%d", &H, &W, &N);
		room_W = N/H+1;
		room_H = N%H;
		if (room_H == 0) { room_H = H; room_W = N / H; }
		if (room_W < 10) printf("%d0%d\n", room_H, room_W);
		else printf("%d%d\n", room_H, room_W);
	}
	return 0;
}
