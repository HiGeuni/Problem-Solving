#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAX = 500001;
int a[MAX];
int sorted[MAX];
ll cnt =0;
void merge(int s, int m, int e){
    int i, j, k;
    i = s; j = m+1; k = s;
    while(i<=m && j<=e){
        if(a[i] <= a[j]){
            sorted[k++] = a[i++];
        }else{
            cnt += (m - i + 1);
            sorted[k++] = a[j++];
        }
    }
    if(i > m){
        while(j <= e){
            sorted[k++] = a[j++];
        }
    }else{
        while(i<=m){
            sorted[k++] = a[i++];
        }
    }
    for(i = s; i<=e; ++i){
        a[i] = sorted[i];
    }
}
void mergesort(int s, int e){
    int m;
    if(s<e){
        m = (s+e)/2;
        mergesort(s, m);
        mergesort(m+1, e);
        merge(s, m, e);
    }
}

int main(){
    int N;
    scanf("%d", &N);
    for(int i=0;i<N; ++i){
        scanf("%d", &a[i]);
    }
    mergesort(0, N-1);
    printf("%lld", cnt);
    return 0;
}