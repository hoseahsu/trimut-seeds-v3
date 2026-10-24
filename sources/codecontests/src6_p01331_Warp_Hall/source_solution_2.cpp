#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define inc(i, l, r) for (int i = l; i <= r; i++)
#define dec(i, l, r) for (int i = l; i >= r; i--)
#define pii pair<int, int>
#define fi first
#define se second
#define pb push_back

const int maxn = 1e3 + 5;
const int maxnum = 2e5;
const int mod = 1e9 + 7;

int add(int a, int b) { return (a + b) % mod; }
int sub(int a, int b) { return (a - b + mod) % mod; }
int mul(int a, int b) { return 1LL * a * b % mod; }

struct worm {
    int x1, y1, x2, y2;
    bool operator<(const worm &o) const {
        if (x1 != o.x1) return x1 < o.x1;
        return y1 < o.y1;
    }
} w[maxn];

int dp[maxn], n, m, k;

inline ll ksm(ll _a, ll _n) {
    ll _r = 1;
    while (_n) {
        if (_n & 1) _r = _r * _a % mod;
        _a = _a * _a % mod;
        _n >>= 1;
    }
    return _r;
}

int fac[maxnum + 5];
int C(int _n, int _m) {
    return mul(mul(fac[_n], ksm(fac[_n - _m], mod - 2)), ksm(fac[_m], mod - 2));
}

int cal(int x1, int y1, int x2, int y2) {
    if (x1 > x2 || y1 > y2) return 0;
    return C(x2 - x1 + y2 - y1, x2 - x1);
}

int main() {
    fac[0] = 1;
    inc(i, 1, maxnum) fac[i] = mul(fac[i - 1], i);
    while (scanf("%d %d %d", &n, &m, &k) != EOF && n) {
        inc(i, 0, k - 1)
            scanf("%d %d %d %d", &w[i].x1, &w[i].y1, &w[i].x2, &w[i].y2);

        sort(w, w + k);
        w[k] = {n, m, n, m};
        for (int i = 0; i <= k; i++) {
            dp[i] = cal(1, 1, w[i].x1, w[i].y1);
            for (int j = 0; j < i; j++) {
                dp[i] = sub(
                    dp[i], mul(dp[j], cal(w[j].x1, w[j].y1, w[i].x1, w[i].y1)));
                dp[i] = add(
                    dp[i], mul(dp[j], cal(w[j].x2, w[j].y2, w[i].x1, w[i].y1)));
            }
        }
        printf("%d\n", dp[k]);
    }
}
