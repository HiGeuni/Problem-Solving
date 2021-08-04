#include<iostream>
#include<string>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int buf[1001][3];
int N;

int inorder(int n) {
    if (buf[n][0] < 0) {
        int a = inorder(buf[n][1]);
        int b = inorder(buf[n][2]);
        if (buf[n][0] == -1) {
            return a + b;
        }
        else if (buf[n][0] == -2) {
            return a - b;
        }
        else if (buf[n][0] == -3) {
            return a * b;
        }
        else if (buf[n][0] == -4) {
            return a / b;
        }
        else {
            return buf[n][0];
        }
    }
    return buf[n][0];
}

int main() {
    for (int tc = 1; tc <= 10; ++tc) {
        int parent, child1, child2;
        string s;
        cin >> N;
        for (int i = 1; i <= N; ++i) {
            cin >> parent >> s;
            if (s == "+") {
                buf[parent][0] = -1;
            }
            else if (s == "-") {
                buf[parent][0] = -2;
            }
            else if (s == "*") {
                buf[parent][0] = -3;
            }
            else if (s == "/") {
                buf[parent][0] = -4;
            }
            else {
                buf[parent][0] = stoi(s);
            }
            if (s == "+" || s == "-" || s == "*" || s == "/") {
                cin >> buf[parent][1] >> buf[parent][2];
            }
        }
        cout << "#" << tc << " "<<inorder(1);
        cout << '\n';
    }
    return 0;
}
