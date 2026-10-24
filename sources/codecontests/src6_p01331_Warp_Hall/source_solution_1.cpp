#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<set>
#include<list>
#include<queue>
#include<deque>
#include<algorithm>
#include<numeric>
#include<utility>
#include<complex>
#include<functional>
 
using namespace std;

/* constant */

const int MAX_N = 100000;
const int MAX_M = 100000;
const int MAX_K = 1000;

const int MAX_F = MAX_N + MAX_M;
const long long MOD = 1000000007;

/* typedef */

typedef long long ll;

struct WH {
  int x0, y0, x1, y1;
  WH() {}
  WH(int _x0, int _y0, int _x1, int _y1): x0(_x0), y0(_y0), x1(_x1), y1(_y1) {}
  bool operator<(const WH& w) const {
    return x0 < w.x0 || (x0 == w.x0 && y0 < w.y0);
  }
};

/* global variables */

int n, m, k;
WH whs[MAX_K];
ll facts[MAX_F + 1], ifacts[MAX_F + 1];
ll dp[MAX_K];

/* subroutines */

ll powmod(ll a, int b) {	// a^b
  ll p = 1;
  while (b > 0) {
    if (b & 1) p = (p * a) % MOD;
    a = (a * a) % MOD;
    b >>= 1;
  }
  return p;
}

ll comb(ll a, ll b) {	// a_C_b (a >= b)
  ll f0 = facts[a], if0 = ifacts[b], if1 = ifacts[a - b];
  return (((f0 * if0) % MOD) * if1) % MOD;
}

ll f(ll x0, ll y0, ll x1, ll y1) {
  ll dx = x1 - x0, dy = y1 - y0;
  return (dx < 0 || dy < 0) ? 0LL : comb(dx + dy, dx);
}

/* main */

int main() {
  facts[0] = ifacts[0] = 1;
  for (ll i = 1; i <= MAX_F; i++) {
    facts[i] = (facts[i - 1] * i) % MOD;
    ifacts[i] = powmod(facts[i], MOD - 2);
  }

  for (;;) {
    cin >> n >> m >> k;
    if (n == 0) break;

    for (int i = 0; i < k; i++)
      cin >> whs[i].x0 >> whs[i].y0 >> whs[i].x1 >> whs[i].y1;
    sort(whs, whs + k);

    for (int i = 0; i < k; i++) {
      dp[i] = f(1, 1, whs[i].x0, whs[i].y0);

      for (int j = 0; j < i; j++) {
	ll df =
	  (f(whs[j].x1, whs[j].y1, whs[i].x0, whs[i].y0) -
	   f(whs[j].x0, whs[j].y0, whs[i].x0, whs[i].y0) + MOD) % MOD;
	dp[i]  = (dp[i] + (dp[j] * df) % MOD) % MOD;
      }
    }

    ll count = f(1, 1, n, m);

    for (int i = 0; i < k; i++) {
      ll df =
	(f(whs[i].x1, whs[i].y1, n, m) -
	 f(whs[i].x0, whs[i].y0, n, m) + MOD) % MOD;
      count = (count + (dp[i] * df) % MOD) % MOD;
    }

    cout << count << endl;
  }

  return 0;
}