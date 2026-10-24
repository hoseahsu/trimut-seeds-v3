# include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    vector <int> s(m), c(m), a(n + 1);
    for (int i = 0; i < m; i++)
    {
        cin >> s[i] >> c[i];
        a[s[i]] = c[i];
    }
    for (int i = 0; i < m; i++)
    {
        if (a[s[i]] != c[i] || (n > 1 && s[i] == 1 && c[i] == 0))
        {
            cout << -1;
            return 0;
        }
    }
    if (a[1] == 0 && n > 1) a[1] = 1;
    for (int i = 1; i <= n; i++)
        cout << a[i];
}