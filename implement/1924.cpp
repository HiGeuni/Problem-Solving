#include <stdio.h>

int main(void)
{
	int arr[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
	int x,n, day, month;
	int sum = 0;
	scanf("%d%d", &month, &day);

	for (x = 0; x < month-1; x++)
	{
		sum += arr[x];
	}
	sum += day;
	n = sum % 7;
	switch (n)
	{
	case 1:
		printf("MON");
		break;
	case 2:
		printf("TUE");
		break;
	case 3:
		printf("WED");
		break;
	case 4:
		printf("THU");
		break;
	case 5:
		printf("FRI");
		break;
	case 6:
		printf("SAT");
		break;
	case 0:
		printf("SUN");
		break;
	default :
		return 0;
	}
}
