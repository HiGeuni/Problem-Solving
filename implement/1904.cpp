#include<iostream>
using namespace std;
long long tile[1000001];

int main()
{
	int n;
	tile[0] = 1;
	tile[1] = 2;
	cin >> n;
	for (int i = 2; i < n; i++) {
		tile[i] = (tile[i - 1] + tile[i - 2]) % 15746;
	}
	cout << tile[n-1] << endl;
	return 0;
}
