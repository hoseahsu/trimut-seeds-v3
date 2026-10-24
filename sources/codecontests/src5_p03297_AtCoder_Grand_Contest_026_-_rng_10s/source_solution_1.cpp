#include "bits/stdc++.h"
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b) {
	return b ? gcd(b, a%b) : a;
}
int main() {
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		ll A, B, C, D;
		cin >> A >> B >> C >> D;
		if (B > A || B > D) {
			cout << "No" << endl;
		}
		else if (B <= C) {
			cout << "Yes" << endl;
		}
		else {
			ll g = gcd(B, D);
			if (B - g + A%g > C) cout << "No" << endl;
			else cout << "Yes" << endl;
		}
	}
}