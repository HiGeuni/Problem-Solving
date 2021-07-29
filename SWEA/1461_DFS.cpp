#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<iostream>
using namespace std;
vector<pair<int,int>>processor;
vector<vector<int>>map(13, vector<int>(13));

int N, M;
int ans = 0;
int maxCon = 0;
int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};
// n : processor number
void dfs(int n,int connect, int curCnt){
    if(n == M){
//        printf("curCnt : %d, connect : %d\n", curCnt, connect);
//
//        for(int i=0;i<N; ++i){
//            for(int j=0;j<N; ++j){
//                printf("%d ", map[i][j]);
//            }
//            printf("\n");
//        }
        if(maxCon < connect){
            maxCon = connect;
            ans = curCnt;
        }
        else if(maxCon == connect){
            ans = min(ans, curCnt);
        }
        return;
    }

    for(int i=0;i<4; ++i){
        bool canLay = false;
        int tx = processor[n].first;
        int ty = processor[n].second;
        while(true){
            if(tx == 0 || tx == N-1 || ty == 0 || ty == N-1){
                canLay = true;
                break;
            }
            tx += dx[i];
            ty += dy[i];
            if(map[tx][ty] == 0) continue;
            else break;
        }
        int cnt = 0;
        if(canLay){
            tx = processor[n].first;
            ty = processor[n].second;
            while(true){
                if(tx == 0 || tx == N-1 || ty == 0 || ty == N-1) break;
                tx += dx[i];
                ty += dy[i];
                map[tx][ty] = 2;
                cnt += 1;
            }
            dfs(n+1, connect + 1,curCnt + cnt);
            tx = processor[n].first;
            ty = processor[n].second;

            while(true){
                if(tx == 0 || tx == N-1 || ty == 0 || ty == N-1) break;
                tx += dx[i];
                ty += dy[i];
                map[tx][ty] = 0;
            }
        }
    }
    dfs(n+1, connect, curCnt);
}

int main(int argc, char** argv)
{
    int test_case;
    int T;
    /*
       아래의 freopen 함수는 input.txt 를 read only 형식으로 연 후,
       앞으로 표준 입력(키보드) 대신 input.txt 파일로부터 읽어오겠다는 의미의 코드입니다.
       //여러분이 작성한 코드를 테스트 할 때, 편의를 위해서 input.txt에 입력을 저장한 후,
       freopen 함수를 이용하면 이후 cin 을 수행할 때 표준 입력 대신 파일로부터 입력을 받아올 수 있습니다.
       따라서 테스트를 수행할 때에는 아래 주석을 지우고 이 함수를 사용하셔도 좋습니다.
       freopen 함수를 사용하기 위해서는 #include <cstdio>, 혹은 #include <stdio.h> 가 필요합니다.
       단, 채점을 위해 코드를 제출하실 때에는 반드시 freopen 함수를 지우거나 주석 처리 하셔야 합니다.
    */
    //freopen("input.txt", "r", stdin);
    scanf("%d", &T);
    /*
       여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
    */
    for(test_case = 1; test_case <= T; ++test_case)
    {
        maxCon = 0;
        ans = 0;
        processor.clear();
        scanf("%d", &N);
        M = 0;
        for(int i=0;i<N; ++i){
            for(int j=0;j<N; ++j){
                scanf("%d", &map[i][j]);
                if(map[i][j] == 1){
                    if(i != 0 && i != N-1 && j != 0 &&j != N-1){
                        M+=1;
                        processor.push_back({i, j});
                    }
                }
            }
        }
        dfs(0, 0, 0);
        printf("#%d %d\n",test_case, ans);
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}