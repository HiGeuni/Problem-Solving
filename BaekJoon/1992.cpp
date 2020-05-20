#include<bits/stdc++.h> 
using namespace std;
 
int arr[64][64];
 
int func(int n, int y, int x) {
	if (n == 1) { 
        cout <<arr[y][x];
        return 0;
    }
    
    int find = arr[y][x];
    for (int i = y; i < y + n; i++) 
        for (int j = x; j < x + n; j++) {
        	if (find != arr[i][j]) {
                cout << "(";
                func(n/2, y, x);
                func(n/2, y, x + n/2);
                func(n/2, y + n/2, x);
                func(n/2, y + n/2, x + n/2);
                cout << ")";
                return 0;
            }
        }
    cout << find;
    return 0;
}
 
int main() {
    int N;
    string num;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> num;
        for (int j = 0; j < N; j++)
            arr[i][j] = num[j] - '0';
    }
 
    func(N, 0, 0);
 
    return 0;
}
