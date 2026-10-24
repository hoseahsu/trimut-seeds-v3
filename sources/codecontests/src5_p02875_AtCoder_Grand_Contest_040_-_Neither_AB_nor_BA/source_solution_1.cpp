#include <bits/stdc++.h>

#define int long long

using namespace std;

const int maxn = 1e7 + 9, mod = 998244353;
int fac[maxn], tw[maxn], ifac[maxn], n;

int pw(int base, int power)
{
    int res = 1;
    while (power) {
        if (power & 1)
            (res *= base) %= mod;
        (base *= base) %= mod;
        power >>= 1;
    }
    return res;
}

int C(int n, int k) { return fac[n] * ifac[k] % mod * ifac[n - k] % mod; }

signed main()
{
    ios::sync_with_stdio(false);
    cin >> n;

    fac[0] = 1;
    for (int i = 1; i < maxn; i++)
        fac[i] = fac[i - 1] * i % mod;
    ifac[maxn - 1] = pw(fac[maxn - 1], mod - 2);
    for (int i = maxn - 2; ~i; i--)
        ifac[i] = ifac[i + 1] * (i + 1) % mod;
    tw[0] = 1;
    for (int i = 1; i < maxn; i++)
        tw[i] = tw[i - 1] * 2 % mod;

    int ans = pw(3, n);
    for (int i = n / 2 + 1; i <= n; i++) {
        (ans += mod - C(n, i) * tw[n - i + 1] % mod) %= mod;
    }

    cout << ans;

    return 0;
}
