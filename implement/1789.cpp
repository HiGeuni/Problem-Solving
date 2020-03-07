#include<stdio.h>
 
int main() {
    long long sum;
    long long n = 1;
 
    scanf("%lld",&sum);
 
    while ((n + 1)*n / 2 <= sum) {
        n++;
    }
    printf("%lld\n",n-1);
 
    return 0;
}
