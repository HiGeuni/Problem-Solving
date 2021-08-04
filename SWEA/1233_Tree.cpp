#include<iostream>
#include<string>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int buf[201][3];
int N;
bool flag;

int inorder(int n) {
    int ans = -2e9;
    if (buf[n][0] < 0) {
        int a = inorder(buf[n][1]);
        int b = inorder(buf[n][2]);
        if(a == -2e9 || b == -2e9){
            flag = false;
            return -2e9;
        }
        if (buf[n][0] == -1) {
            return ans = a + b;
        }
        else if (buf[n][0] == -2) {
            return ans = a - b;
        }
        else if (buf[n][0] == -3) {
            return ans = a * b;
        }
        else if (buf[n][0] == -4) {
            return ans = a / b;
        }
        else {
            return ans = buf[n][0];
        }
    }
    return ans;
}

int main() {
    for (int tc = 1; tc <= 10; ++tc) {
        int parent;
        string child1, child2;
        flag = true;
        string s;
        cin >> N;
        for (int i = 1; i <= N; ++i) {
            cin >> parent >> s;
            if(i <=  N/2){
                if(i == N/2 && N%2 ==0){
                    cin>>child1;
                }else{
                    cin>>child1>>child2;
                }
                if(s[0] >= '0' && s[0] <='9'){
                    flag = false;
                }
            }else{
                if(s[0] <'0' || s[0] > '9'){
                    flag = false;
                }
            }
        }
        cout << "#" << tc << " "<<flag;
        cout << '\n';
    }
    return 0;
}