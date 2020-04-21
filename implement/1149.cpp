#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;
int t;
int dp[1010][5];
int ColorAndHouse[1010][1010];

int dis(int i, int color)
{
   int & ret = dp[i][color];
   if (i > t)
      return 0;
   else if(ret==-1){
      ret = ColorAndHouse[i][color];
      if (color == 1) ret += min(dis(i + 1, 2), dis(i + 1, 3));
      else if (color == 2) ret += min(dis(i + 1, 1), dis(i + 1, 3));
      else if (color == 3) ret += min(dis(i + 1, 1), dis(i + 1, 2));
   }
   return ret;
}
int main()
{
   cin >> t;

   memset(dp, -1, sizeof(dp));

   for (int i = 1; i <= t; i++) {
      for (int j = 1; j <= 3; j++) {
         cin >> ColorAndHouse[i][j];
      }
   }
   cout << min({ min(dis(1,1),dis(1,2)), dis(1,3) });
   return 0;
}
