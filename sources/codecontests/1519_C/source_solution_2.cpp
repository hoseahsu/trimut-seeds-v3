#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define deb(x) cout << #x << " " << x << endl;
#define mod 1000000007
#define mod2 998244353
#define fast std::ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
#define endl "\n"
const ll INF = 1e18;
const ll NEGINF = -1 * INF;

/*NOTES: Take care of ll vs int
         Never use an iterator after erasing it.
*/

void solve()
{
    int n;
    cin >> n;
    vector<int> u(n);
    for (int i = 0; i < n; i++)
    {
        cin >> u[i];
        u[i]--;
    }
    vector<vector<ll>> arr(n, vector<ll>());
    vector<ll> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        arr[u[i]].push_back(s[i]);
    }
    for (int i = 0; i < n; i++)
    {
        sort(arr[i].begin(), arr[i].end(), greater<ll>());
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < arr[i].size(); j++)
        {
            arr[i][j] += arr[i][j - 1];
        }
    }
    vector<ll> result(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (arr[i].size() == 0)
        {
            continue;
        }
        for (int k = 1; k <= arr[i].size(); k++)
        {
            int teams = arr[i].size() / k;
            int elements = k * teams;
            result[k - 1] += arr[i][elements - 1];
        }
    }
    for (ll x : result)
    {
        cout << x << " ";
    }
    cout << endl;
}

int main()
{
    fast;
#ifndef ONLINE_JUDGE
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/input.txt", "r", stdin);
    freopen("/home/kalit/Desktop/Data Structures-Algo-Competitive/src/codeforces/output.txt", "w", stdout);
#endif
    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    //cout<< "Done in " << clock() / CLOCKS_PER_SEC <<"sec"<< endl;
    return 0;
}