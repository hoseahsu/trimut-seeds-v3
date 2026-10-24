#include <bits/stdc++.h>

using namespace std;

#define ll long long

/* aとbの最大公約数を求める. */
ll gcd(ll a, ll b) {
	if (b > a) return gcd(b, a);
	if (b == 0) return a;
	return gcd(b, a % b);
}

/* ax+by=gcd(a,b)を満たす(x,y)を格納し、gcd(a,b)を返す. */
ll extgcd(ll a, ll b, ll& x, ll& y) {
	if (b > a) return extgcd(b, a, y, x);
	if (b == 0) {
		x = 1; y = 0;
		return a;
	}
	ll g = extgcd(b, a % b, y, x);
	y -= (a / b) * x;
	return g;
}

/* mod mでのaの逆元を求める.(gcd(a,m) = 1) */
ll modinv(ll a, ll m) {
	ll x, y;
	extgcd(a, m, x, y);
	return (m + x % m) % m;
}

/* 連立線形方程式を解く.
		A[i] * x ≡ B[i] (mod M[i])
	なる方程式の解が
		x ≡ b (mod m)
	とかけるとき、(b, m)を返す.(存在しなければ(0, -1)) */
pair<ll, ll> liner_congruence(
	vector<ll> A, vector<ll> B, vector<ll> M
) {
	ll x = 0, m = 1;

	for (int i = 0; i < A.size(); ++i) {
		ll a = A[i] * m,
			b = B[i] - A[i] * x,
			d = gcd(M[i], a);

		if (b % d != 0) // 解なし
			return make_pair(0, -1);

		ll t = b / d * modinv(a / d, M[i] / d) % (M[i] / d);
		x = x + m * t;
		m *= M[i] / d;
	}

	return make_pair(x % m, m);
}

signed main() {
	int n; cin >> n;
	vector<int> p(n), q(n);
	for (int i = 0; i < n; ++i)
		cin >> p[i];
	for (int i = 0; i < n; ++i)
		cin >> q[i];

	// dp[i][j] := 数字iがj日後に何に書き換わるか
	int dp[201][201];
	for (int i = 1; i <= n; ++i) // 初期化
		dp[i][0] = i;
	for (int j = 1; j <= 200; ++j)
		for (int i = 1; i <= n; ++i)
			dp[i][j] = q[dp[i][j - 1] - 1];

	// i番目の数字について、
	// ・B[i-1]日後に初めてiになり、
	// ・M[i-1]日周期で数字が繰り返す
	// を求める.(i=1,2,...,n)
	vector<ll> B(n);
	for (int i = 1; i <= n; ++i) {
		B[i - 1] = -1;
		int pi = p[i - 1]; // 0日目の数字
		for (int j = 0; j <= 200; ++j) {
			if (dp[pi][j] == i) {
				B[i - 1] = j;
				break;
			}
		}
		if (B[i - 1] == -1) { // iになることがなければ-1
			cout << -1 << endl;
			return 0;
		}
	}

	vector<ll> M(n);
	for (int i = 1; i <= n; ++i) {
		M[i - 1] = -1;
		int pi = p[i - 1]; // 0日目の数字
		for (int j = 1; j <= 200; ++j) {
			if (dp[pi][j] == pi) {
				M[i - 1] = j;
				break;
			}
		}
	}

	vector<ll> A(n, 1);
	auto ans = (liner_congruence(A, B, M));
	if (ans.second == -1) {
		cout << -1 << endl;
	}
	else if (ans.first >= 0) {
		cout << ans.first << endl;
	}
	else {
		cout << (ans.first + ans.second) << endl;
	}

	return 0;
}
