#include<bits/stdc++.h>
using namespace std;

#define MOD 1000000007

void cross(long long a[2][2], long long b[2][2]){
    long long x, y, z, w;
    x = a[0][0]*b[0][0] + a[0][1]*b[1][0];
    y = a[1][0]*b[0][0] + a[1][1]*b[1][0];
    z = a[0][0]*b[0][1] + a[0][1]*b[1][1];
    w = a[1][0]*b[0][1] + a[1][1]*b[1][1];
    a[0][0] = x % MOD;
    a[1][0] = y % MOD;
    a[0][1] = z % MOD;
    a[1][1] = w % MOD;
}


void power(long long F[2][2],long long n){
    if(n==0 || n == 1){
        return;
    }
    long long tmp[2][2] = {{1,1}, {1,0}};
    power(F, n/2);
    cross(F, F);
    if( n & 1){
        cross(F, tmp);
    }
}

long long solve(long long n){
    long long fib[2][2] = {{1,1}, {1,0}};
    if(n == 0) return 0;
    power(fib, n-1);
    return fib[0][0];
}
int main(){
    long long N;
    cin>>N;
    cout<<solve(N);
    return 0;
}
