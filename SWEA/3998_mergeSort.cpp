#include<cstdio>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;
#define MAXN 100001

//Merge Sort
int A[MAXN + 10];
int sorted[MAXN + 10];
long long ans;

void merge(int l, int m, int r) {
    int i, j, k;
    i = l; j = m + 1; k = l;
    while (i <= m && j <= r) {
        if (A[i] <= A[j])
            sorted[k++] = A[i++];
        else {
            ans += (m-i+1);
            sorted[k++] = A[j++];
        }
    }

    // 남아있는 값들 일괄 복사
    if (i > m) {
        while (j <= r)
            sorted[k++] = A[j++];
    }
    else {
        while (i <= m)
            sorted[k++] = A[i++];
    }

    // 배열 복사
    for (i = l; i <= r; i++)
        A[i] = sorted[i];
}

void mergeSort(int l, int r) {
    int m;
    if (l < r) {
        m = (l + r) / 2;
        mergeSort(l, m);
        mergeSort(m + 1, r);
        merge(l, m, r);
    }
}

int main(){
    int testCase;
    scanf("%d", &testCase);
    for(int tc = 1; tc <= testCase; ++tc){
        ans = 0;
        int N;
        memset(A, 0, sizeof(A));
        scanf("%d", &N);
        for(int i=0;i<N; ++i)
            scanf("%d", &A[i]);
        mergeSort(0, N-1);
        printf("#%d %lld\n", tc, ans);
    }
    return 0;
}