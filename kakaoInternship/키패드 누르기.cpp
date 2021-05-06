#include <string>
#include <vector>
#include <utility>
#include<iostream>
using namespace std;


//1,4,7 : 왼손 엄지
//3,6,9 : 오른손 엄지
//2,5,8,0 : 두 엄지손가락의 현재 키패드의 위치에서 더 가까운 손가락

string solution(vector<int> numbers, string hand) {
    vector<pair<int,int>> grid;
    grid.push_back({3, 1});
    
    for(int i=0;i<3; ++i)
        for(int j=0;j<3; ++j)
            grid.push_back({i, j});
    grid.push_back({3,0});
    grid.push_back({3,2});

    string answer = "";
    int left = 10;
    int right = 11;
    for(auto x : numbers){
        if(x == 1 || x == 4 || x == 7){
            answer += "L";
            left = x;
        }else if(x == 3 || x == 6 || x == 9){
            answer += "R";
            right = x;
        }else{
            int Ldis = abs(grid[left].first - grid[x].first)+abs(grid[left].second-grid[x].second);
            int Rdis = abs(grid[right].first - grid[x].first)+abs(grid[right].second-grid[x].second);
            if(Ldis > Rdis){
                answer += "R";
                right = x;
            }else if (Ldis < Rdis){
                answer += "L";
                left = x;
            }else{
                if(hand == "left"){
                    answer += "L";
                    left = x;
                }
                else{
                    answer += "R";
                    right = x;
                }
            }
        }
    }
    return answer;
}
