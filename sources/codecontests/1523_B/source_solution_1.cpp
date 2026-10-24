#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
ll mod = 1000000007;
ll maxn = 10000;
#define fi first
#define sec second
// ll powy(ll a, ll b)
// {
//     if (b == 0) return 1;
//     ll c = powy(a, b / 2);
//     if (b % 2 == 1) return (((c * c) % mod) * a) % mod;
//     else return ((c * c) % mod);
// }
// vector<ll> fib(maxn);
// void calc()
// {
//     fib[0] = 0; fib[1] = 1;
//     for (ll i = 2; i < maxn; i++)
//         fib[i] = (fib[i - 1] + fib[i - 2]) % mod;
// }
// vector<ll> fact(maxn);
// void pc()
// {
//     fact[0] = 1;
//     for (ll i = 1; i < maxn; i++)
//         fact[i] = (fact[i - 1] * i) % mod;
// }
// ll ncr(ll n, ll r)
// {
//     if (n < r) return 0;
//     if (n == r) return 1;
//     if (r == 0) return 1;
//     ll inv = powy((fact[n - r] * fact[r]) % mod, mod - 2) % mod;
//     ll ans = (inv * fact[n]) % mod;
//     return ans;
// }
// const int N = 10000;
// int lp[N + 1];
// vector<int> pr;
// void sieve() {
//     for (int i = 2; i <= N; ++i) {
//         if (lp[i] == 0) {
//             lp[i] = i;
//             pr.push_back (i);
//         }
//         for (int j = 0; j < (int)pr.size() && pr[j] <= lp[i] && i * pr[j] <= N; ++j)
//             lp[i * pr[j]] = pr[j];
//     }
// }
bool cmp(pair<ll, pair<ll, string> > p1, pair<ll, pair<ll, string> > p2)
{
    if (p1.fi > p2.fi) return true;
    else if (p2.fi > p1.fi) return false;
    else
    {
        if (p1.sec.fi > p2.sec.fi) return true;
        else return false;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        vector<ll> vec(n);
        for (ll i = 0; i < n; i++)
        {
            cin >> vec[i];
        }
        ll k = (3 * n);
        cout << k << "\n";
        for (ll i = 0; i < n - 1; i += 2)
        {
            cout << "1 " << i + 1 << " " << i + 2 << "\n";
            cout << "2 " << i + 1 << " " << i + 2 << "\n";
            cout << "1 " << i + 1 << " " << i + 2 << "\n";
            cout << "2 " << i + 1 << " " << i + 2 << "\n";
            cout << "1 " << i + 1 << " " << i + 2 << "\n";
            cout << "2 " << i + 1 << " " << i + 2 << "\n";
        }
    }
    return 0;
}
