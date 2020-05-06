#include<stdio.h>
#define width w-x
#define height h-y

int main(void)
{
	int x, y, w, h,max_x,max_y;
	scanf("%d%d%d%d", &x, &y, &w, &h);
	if (width > x) 	max_x = x;
	else max_x = width;
	if (height > y)	max_y = y;
	else max_y = height;
	if (max_x > max_y) printf("%d\n", max_y);
	else printf("%d\n", max_x);
	return 0;
}
