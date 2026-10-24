//o ro pe ohunkan yoo wa nibi
#include <bits/stdc++.h>
#define endl '\n'
#define S second
#define F first
#define pb push_back
#define ll long long
#define ull unsigned long long

using namespace std;

const long long mod = (1e9) + 7;
int32_t main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    int t;
    cin >> t;
    for(int z = 0;z < t;++ z)
    {
        ll n , k;
        cin >> n >> k;
        ll r[n];
        for(int i = 0;i < n;++ i)
        {
            cin >> r[i];
        }
        sort(r , r + n);
        reverse(r , r + n);
        ll i = 0 , kol = 0 , m;
        while(i < n && r[i] != r[k - 1])
        {
            ++ i;
        }
        m = k - i;
        while(i < n && r[i] == r[k - 1])
        {
            ++ i;
            ++ kol;
        }
        ll p[kol + 2][m + 2];
        for(int jj = 0;jj <= kol;++ jj)
        {
            for(int j = 0;j <= m;++ j)
            {
                p[jj][j] = 0;
                if(j == 0)
                {
                    p[jj][j] = 1;
                }
            }
        }
        for(int s = 1;s <= kol;++ s)
        {
            for(int j = 1;j <= m;++ j)
            {
                p[s][j] = p[s - 1][j] + p[s - 1][j - 1];
                p[s][j] %= mod;
            }
        }
        cout << p[kol][m] << endl;
    }
	return 0;
}
