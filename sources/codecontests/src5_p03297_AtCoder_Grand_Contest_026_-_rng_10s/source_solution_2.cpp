#include <iostream>
#include <algorithm>
using namespace std;
long long gcd(long long x, long long y) {
	if (y == 0) return x;
	return gcd(y, x % y);
}
int Q; long long A, B, C, D;
int main() {
	cin >> Q;
	while (Q--) {
		cin >> A >> B >> C >> D;
		long long G = gcd(B, D);
		long long mn = A - (A - C - 1) / G * G - B;
		cout << (A < B || B > D || mn < 0 ? "No" : "Yes") << '\n';
	}
	return 0;
}