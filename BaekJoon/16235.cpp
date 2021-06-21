//
// Created by 김효근 on 2021/06/22.
//
//봄에는 자신의 나이만큼 양분먹고, 나이 1 증가 자신의 칸에 있는 양분만, 어린친구부터
//먹지못하면 즉시 죽는다.
//여름에는 죽은 나무 -> 양분으로 (+ 죽은 나무 나이 // 2)
//나무의 나이가 5의 배수면 인접칸에 나이가 1인 나무 생성
//겨울에는 양분 추가 A[r][c]

#include<cstdio>
#include<vector>
#include<algorithm>
typedef long long ll;
using namespace std;

int dx[8] = {-1,-1,-1,0,0,1,1,1};
int dy[8] = {1,0,-1,1,-1,1,0,-1};

int main(){
    int n,m,K, ta, tb, tc;
    scanf("%d%d%d", &n, &m, &K);

    int nutrient[10][10];
    int addNutrient[10][10];
    vector<int> trees[10][10];
    for(int i=0; i<n; ++i)
        for(int j=0; j<n; ++j) {
            scanf("%d", &addNutrient[i][j]);
        }
    for(int i=0;i<m; ++i){
        scanf("%d%d%d", &ta, &tb, &tc);
        trees[ta-1][tb-1].push_back(tc);
    }
    for(int i=0;i<n; ++i){
        for(int j=0;j<n; ++j){
            nutrient[i][j] = 5;
        }
    }
    for(int t = 0;t<K; ++t){
        //sort
        for(int i=0;i<n;++i)
            for(int j=0;j<n; ++j)
                sort(trees[i][j].begin(), trees[i][j].end());
        //spring & summer
        for(int i=0;i<n;++i){
            for(int j=0;j<n; ++j){
                bool flag = true;
                for(int k=0; k < trees[i][j].size(); ++k){
                    if(flag){
                        if(nutrient[i][j] >= trees[i][j][k]){
                            nutrient[i][j] -= trees[i][j][k];
                            trees[i][j][k] +=1;
                        }else{
                            flag = false;
                            nutrient[i][j] += int(trees[i][j][k]/2);
                            trees[i][j].erase(trees[i][j].begin() + k);
                            k -=1;
                        }
                    }
                    else{
                        nutrient[i][j] += int(trees[i][j][k]/2);
                        trees[i][j].erase(trees[i][j].begin() + k);
                        k -=1;
                    }
                }
            }
        }

        //fall
        for(int i=0;i<n;++i){
            for(int j=0;j<n; ++j){
                for(int k=0;k<trees[i][j].size(); ++k){
                    if(trees[i][j][k]%5 == 0){
                        for(int tx = 0; tx <8; tx++){
                            if(dx[tx] + i>=0 && dx[tx]+i < n && dy[tx]+j >=0 && dy[tx]+j<n){
                                trees[dx[tx]+i][dy[tx]+j].push_back(1);
                            }
                        }
                    }
                }
            }
        }
        //winter
        for(int i=0;i<n;++i){
            for(int j=0;j<n; ++j){
                nutrient[i][j] += addNutrient[i][j];
            }
        }
    }
    int cnt =0;
    for(int i=0;i<n;++i) {
        for (int j = 0; j < n; ++j) {
            cnt += trees[i][j].size();
        }
    }
    printf("%d", cnt);
    return 0;
}
