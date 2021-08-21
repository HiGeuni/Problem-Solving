#include <vector>
#include <queue>
#include<algorithm>
#include <utility>
#include <iostream>
using namespace std;

queue<pair<int, int>> q; // 행, 열
vector<vector<bool>> visited;

//상,하,좌,우
int y[] = { 1,-1,0,0 };
int x[] = { 0,0, 1,-1 };

int BFS(int m, int n, vector<vector<int>> picture) {
    int areaCnt = 0;

    while (!q.empty()) {
        areaCnt += 1;
        int currY = q.front().first;
        int currX = q.front().second;
//        cout<<currY<<" "<<currX<<endl;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nextY = currY + y[i];
            int nextX = currX + x[i];
            if (0 <= nextY && nextY < m && 0 <= nextX && nextX < n) {
                if (!visited[nextY][nextX] && picture[currY][currX] == picture[nextY][nextX]) {
                    visited[nextY][nextX] = true;
                    q.push({ nextY, nextX });

                }
            }

        }
    }

    return areaCnt;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    int areaCnt;
    visited.clear();
    visited.resize(m, vector<bool>(n, false));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j] && picture[i][j]!=0) {
                q.push({ i, j });
                visited[i][j] = true;
                areaCnt = BFS(m, n, picture);
                max_size_of_one_area = max(max_size_of_one_area, areaCnt);
                number_of_area++;
            }
        }
    }

//    for (int i = 0; i < m; i++) {
//        for (int j = 0; j < n; j++) {
//            cout << visited[i][j];
//        }
//        cout << endl;
//    }

    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
//    cout<<answer[0] <<" "<<answer[1]<<" ";
    return answer;
}
