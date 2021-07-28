#include<bits/stdc++.h>
using namespace std;

int main(){
    cin.tie();
    ios_base::sync_with_stdio(false);
    deque<char>dq;
    string s;
    bool prevA = false;
    bool flag = true;
    cin>>s;
    for(int i=0;i<s.size(); ++i){
        if(s.size() == 1 && s[i] == 'A') flag = false;
        dq.push_back(s[i]);
        if(s[i] == 'P' && prevA){
            for(int j=0; j<4; ++j){
                if(dq.empty()){
                    flag = false;
                    break;
                }
                if(j != 1){
                    if(dq.back() == 'P') dq.pop_back();
                    else{
                        flag = false;
                    }
                }else{
                    if(dq.back() == 'A') dq.pop_back();
                    else{
                        flag = false;
                    }
                }
            }
            if(flag) dq.push_back('P');
        }
        if(s[i] == 'A') prevA = true;
        else prevA = false;
    }
    if(dq.size() != 1 || dq.back() != 'P') flag = false;
    if(!flag) cout<<"NP"<<'\n';
    else cout<<"PPAP"<<'\n';
    return 0;
}