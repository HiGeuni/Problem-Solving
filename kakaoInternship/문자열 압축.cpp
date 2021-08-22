#include <string>
#include <vector>
#include<algorithm>
using namespace std;

int solution(string s) {
    if(s.size() == 1) return 1;
    int answer = 0;
    int n = s.size();
    int ans = 2e9;
    for(int i=1; i<=n/2; ++i){
        string t = "";
        vector<string>v;
        int j=0;
        while(true){
            v.push_back(s.substr(j, i));
            j += i;
            if(j >= n) break;
        }

        string prev = "";
        int cnt = 0;
        for(j=0; j<v.size(); ++j){
            if(prev == v[j]){
                cnt += 1;
            }else{
                if(cnt == 1){
                    t += prev;
                }else if(cnt != 0){
                    t += to_string(cnt);
                    t += prev;
                }
                prev = v[j];
                cnt = 1;
            }
        }
        if(cnt == 1){
            t += prev;
        }else if(cnt != 0){
            t += to_string(cnt);
            t += prev;
        }

        if(t.size() != 0 && ans > t.size())
            ans = t.size();
    }
    return ans;
}
