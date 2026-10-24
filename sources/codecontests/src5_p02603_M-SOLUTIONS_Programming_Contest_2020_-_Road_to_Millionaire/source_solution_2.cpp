#include <bits/stdc++.h>

using namespace std;

int n, A[220];

long long ans = 1000;

int main() {
	cin >> n;
	for(int i = 1;i <= n; ++i)
		cin >> A[i];
	for(int i = 2;i <= n; ++i) {
		if(A[i] > A[i - 1]) {
			ans = (ans / A[i - 1] * A[i]) + (ans % A[i - 1]);
		}
	}
	cout << ans << endl;
	return 0;
}