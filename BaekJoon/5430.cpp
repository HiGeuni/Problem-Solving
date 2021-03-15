#include<bits/stdc++.h>
using namespace std;

int main(){
    int tc;
    cin>>tc;
    for(int i=0; i<tc; ++i){
        int n;
        string cmd, arr;
        deque<int>num;
        cin>>cmd>>n>>arr;
        string temp = "";
        for(int j=0; j<arr.size(); ++j){
            if('0'<= arr[j] && arr[j]<='9') temp += arr[j];
            else if(arr[j] == '[') continue;
            else if(arr[j] == ',' || arr[j] == ']'){
                if(temp != ""){
                    num.push_back(stoi(temp));
                    temp = "";
                }
            }
        }
        bool isRev = false;
        bool isErr = false;
        for(int j=0; j<cmd.size(); ++j){
            if(isErr) break;
            if(isRev){
                if(cmd[j] == 'R')
                    isRev = false;
                else{
                    if(num.size() == 0)
                        isErr = true;
                    else
                        num.pop_back();
                }
            }else{
                if(cmd[j] == 'R')
                    isRev = true;
                else{
                    if(num.size() == 0)
                        isErr = true;
                    else
                        num.pop_front();
                }
            }
        }
        if(isErr)   cout<<"error"<<'\n';
        else if(isRev){
            cout<<"[";
            while(num.size() != 0){
                if(num.size() == 1)
                    cout<<num.back();
                else
                    cout<<num.back()<<",";
                num.pop_back();
            }
            cout<<"]\n";
        } else{
            cout<<'[';
            while(num.size() != 0){
                if(num.size() == 1)
                    cout<<num.front();
                else
                    cout<<num.front()<<",";
                num.pop_front();
            }
            cout<<"]\n";
        }
    }
    return 0;
}