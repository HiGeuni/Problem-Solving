#include<stdio.h>
#include<math.h>
#define T_distance sqrt((T_x1-T_x2)*(T_x1-T_x2)+(T_y1-T_y2)*(T_y1-T_y2)) 
#define M_distance sqrt((M_r1+M_r2)*(M_r1+M_r2))
int main() {
	int T_x1, T_x2, T_y1, T_y2, M_r1, M_r2, Test_case;
	scanf("%d",&Test_case);
	for (int i = 0; i < Test_case; i++) {
		scanf("%d %d %d %d %d %d", &T_x1, &T_y1, &M_r1, &T_x2, &T_y2, &M_r2);
		if (T_x1 == T_x2 && T_y1 == T_y2) {
			if (M_r1 == M_r2) {
			    printf("-1\n");
		    }
			else if (M_r1 != M_r2) {
				printf("0\n");
			}
		}
		else if (T_distance > M_distance){
			printf("0\n");
		}
		else if (T_distance == M_distance) {
			printf("1\n");
		}
		else if(T_distance<M_distance){
			if (M_r1 > T_distance + M_r2 || M_r2 >T_distance + M_r1)
			{
				printf("0\n");
			}
			else if (M_r1 == T_distance + M_r2 || M_r2 == T_distance + M_r1)
			{
				printf("1\n");
			}
			else if (M_r1 < T_distance + M_r2 || M_r2 < T_distance + M_r1)
			{
				printf("2\n");
			}

		}
	}
	return 0;
}
