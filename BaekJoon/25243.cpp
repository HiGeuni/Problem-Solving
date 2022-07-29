#include<bits/stdc++.h>
using namespace std;
#define X first
#define Y second

typedef pair<int, int> pii;
typedef pair<int, string> pis;

typedef struct train_info {
    int num; // 열차 번호
    int curTime; // 현재 시간
    int startTime; // 시작 시간
}train_info;

bool cmp(const train_info & a, const train_info & b){
    if(a.curTime == b.curTime){
        return a.num < b.num;
    }
    return a.curTime < b.curTime;
}

int parsing(string s) {
    int p = 0;
    int tmp = 0;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == ':') {
            p += 60 * tmp;
            tmp = 0;
        }
        else {
            tmp *= 10;
            tmp += int(s[i] - '0');
        }
    }
    p += tmp;
    return p;
}

void toStringTime(int t) {
    cout << setw(2) << setfill('0') << ((t / 60) % 24) << ":" << setw(2) << setfill('0') << (t % 60) << "\n";
}

int arr[4] = { 7,7,8,10 }; // 소요 시간

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    int C, H, num;
    int curTime = 0;
    string t;
    cin >> C >> H;
    // 영역마다 하나씩 정의, 0번 영역에 들어가길 기다리는지, 1번 영역에 들어가길 기다리는지, ...
    vector<train_info>v[4];
    //false면 들어갈 수 있는 상태임.
    vector<bool>status(4, false);
    vector<train_info>vti[4];
    // 영역별 운행이 끝나는 시간
    vector<int>endTime(4, -1);

    for (int i = 0; i < C + H; ++i) {
        cin >> num >> t;
        int a = parsing(t);
        if (num & 1)
            v[0].push_back({ num, a, a });
        else
            v[3].push_back({ num, a, a });
    }
    for(int i=0; i<4; ++i){
        sort(v[i].begin(), v[i].end(), cmp);
    }
    vector<pii>ans;

    while (true) {
        if (ans.size() == C + H) break;
        for (int i = 0; i < 4; ++i) {
            if (curTime == endTime[i] && status[i]) {
                status[i] = false; // 열어줍니다.
                train_info cur = vti[i].back(); // 기차의 정보
                cur.curTime = curTime + 1; // 대기시간 포함
                vti[i].pop_back();
                endTime[i] = -1;
                if (cur.num & 1) {
                    if (i == 3) {
                        cur.curTime -= 1;
                        ans.push_back({ cur.num, cur.curTime });
                    }
                    else{
                        v[i + 1].push_back(cur);
                        sort(v[i+1].begin(), v[i+1].end(), cmp);
                    } 
                }
                else {
                    if (i == 0) {
                        cur.curTime -= 1;
                        ans.push_back({ cur.num, cur.curTime });
                    }
                    else{
                        v[i - 1].push_back(cur);
                        sort(v[i-1].begin(), v[i-1].end(), cmp);
                    }
                }
            }
            if (status[i]) {
                // 열차가 이미 구간에 있어서 지나갈 수 없다.
                continue;
            }
            else {
                if (!v[i].empty()) {
                    // 들어갈 수 있는 경우
                    int idx = 0;
                    int flag = false;
                    for(int j=0; j<v[i].size(); ++j){

                        if(v[i][j].curTime <= curTime)
                            flag = true;
                        else
                            break;
                        //아래의 경우는 여러가지 후보를 고려하기 위함.
                        // 후보가 많은 경우 시발역에서 출발한 시간이 이를수록 빨리 출발함.
                        if(v[i][j].startTime < v[i][idx].startTime){
                            idx = j;
                        }else if(v[i][j].startTime == v[i][idx].startTime){
                            if(v[i][j].num < v[i][idx].num){
                                idx = j;
                            }
                        }
                    }
                    if(flag){
                        train_info cur = v[i][idx];
                        v[i].erase(v[i].begin() + idx);
                        vti[i].push_back(cur);
                        endTime[i] = curTime + arr[i];
                        status[i] = true;
                    }
                }
                else {
                    continue;
                }
            }
        }
        curTime += 1;
    }

    sort(ans.begin(), ans.end());

    for (int i = 0; i < ans.size(); ++i) {
        toStringTime(ans[i].Y);
    }
    return 0;
}
