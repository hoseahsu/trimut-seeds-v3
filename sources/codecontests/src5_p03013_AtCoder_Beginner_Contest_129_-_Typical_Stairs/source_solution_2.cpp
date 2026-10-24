#include <iostream>
using namespace std;

int main () {
	int n, m, temp, N = 1000000007;
	cin >> n >> m;
	int a[100001] = {0};
	for (int i = 1; i <= m; i++) {cin >> temp; a[temp] = -1;}
	a[1] = a[1] == -1 ? 0 : 1;
	a[2] = a[2] == -1 ? 0 : a[1] == 0 ? 1 : 2;
	for (int i = 3; i <= n; i++) {
		if (a[i] == -1) a[i] = 0;
		else a[i] = (a[i-1] % N + a[i-2] % N) % N;
	}
	cout << a[n] << endl;
	return 0;
}