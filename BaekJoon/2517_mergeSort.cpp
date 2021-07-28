#include<bits/stdc++.h>
using namespace std;

struct run{
    int val;
    int idx;
};

vector<run>v(500001);
vector<run>sorted(500001);
vector<int>max_(500001);

void mergeSort(int s, int m, int e){
    int i = s, j = m+1, k = s;
    while(i <= m && j <= e){
        if(v[i].val >= v[j].val){
            sorted[k++] = v[i++];
        }else{
            max_[v[j].idx] -= m - i + 1;
            sorted[k++] = v[j++];
        }
    }
    if(i > m){
        while(j <= e){
            sorted[k++] = v[j++];
        }
    }else{
        while(i <= m){
            sorted[k++] = v[i++];
        }
    }
    for(i = s; i<=e; ++i){
        v[i] = sorted[i];
    }
}

void merge(int s, int e){
    int mid;
    if(s<e){
        mid = (s+e)/2;
        merge(s, mid);
        merge(mid+1, e);
        mergeSort(s, mid, e);
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int N;
    scanf("%d", &N);
    for(int i=0;i<N; ++i) {
        scanf("%d", &v[i].val);
        v[i].idx = i;
        max_[i] = i+1;
    }
    merge(0, N-1);
    for(int i=0;i<N; ++i){
        printf("%d ", max_[i]);
    }
    return 0;
}#include<bits/stdc++.h>
using namespace std;

struct run{
    int val;
    int idx;
};

vector<run>v(500001);
vector<run>sorted(500001);
vector<int>max_(500001);

void mergeSort(int s, int m, int e){
    int i = s, j = m+1, k = s;
    while(i <= m && j <= e){
        if(v[i].val >= v[j].val){
            sorted[k++] = v[i++];
        }else{
            max_[v[j].idx] -= m - i + 1;
            sorted[k++] = v[j++];
        }
    }
    if(i > m){
        while(j <= e){
            sorted[k++] = v[j++];
        }
    }else{
        while(i <= m){
            sorted[k++] = v[i++];
        }
    }
    for(i = s; i<=e; ++i){
        v[i] = sorted[i];
    }
}

void merge(int s, int e){
    int mid;
    if(s<e){
        mid = (s+e)/2;
        merge(s, mid);
        merge(mid+1, e);
        mergeSort(s, mid, e);
    }
}

int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int N;
    scanf("%d", &N);
    for(int i=0;i<N; ++i) {
        scanf("%d", &v[i].val);
        v[i].idx = i;
        max_[i] = i+1;
    }
    merge(0, N-1);
    for(int i=0;i<N; ++i){
        printf("%d ", max_[i]);
    }
    return 0;
}