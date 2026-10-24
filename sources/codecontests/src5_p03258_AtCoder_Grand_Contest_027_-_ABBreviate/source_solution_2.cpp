#include <bits/stdc++.h>

using namespace std;

int solve(string s)
{
    const int M = 1e9 + 7;
    int n = (int) s.size();
    vector <int> go(n);
    for (int i = n - 1; i >= 0; i--)
    {
        if (i == n - 1 || s[i] == s[i + 1])
        {
            go[i] = i + 1;
        }
        else
        {
            go[i] = go[i + 1];
        }
    }
    if (go[0] == n)
    {
        return 1;
    }
    vector <int> dp(n + 1);
    vector <int> pref(n);
    int sm = 0;
    for (int i = 0; i < n; i++)
    {
        sm += (s[i] - 'a' + 1);
        if (sm >= 3) sm -= 3;
        pref[i] = sm;
    }
    vector <vector <int> > g(n + 1, vector <int> (3, n));
    for (int i = n - 1; i >= 0; i--)
    {
        g[i] = g[i + 1];
        g[i][pref[i]] = i;
    }
    int ans = 0;
    dp[0] = 1;
    for (int i = 0; i < n; i++)
    {
        dp[i + 1] += dp[i];
        if (dp[i + 1] >= M) dp[i + 1] -= M;
        int cur = (s[i] == 'a' ? 2 : 1);
        int ret = go[i];
        int need = ((i ? pref[i - 1] : 0) + cur) % 3;
        int where = g[ret][need];
        if (where + 1 <= n)
        {
            dp[where + 1] += dp[i];
            if (dp[where + 1] >= M) dp[where + 1] -= M;
        }
        if (i != 0 && pref[i - 1] == pref[n - 1])
        {
            ans += dp[i];
            if (ans >= M) ans -= M;
        }
    }
    ans += dp[n];
    if (ans >= M) ans -= M;
    return ans;
}

int main()
{
#ifdef ONPC
    freopen("a.in", "r", stdin);
#endif // ONPC
    string s;
    while (cin >> s)
    {
        cout << solve(s) << '\n';
    }
}
