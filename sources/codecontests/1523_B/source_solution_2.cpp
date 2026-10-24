#include<bits/stdc++.h>
using namespace std;
#define ll long long
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;

// typedef tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>PBDS;
#define mod 1000000007
#define INF 10000000000007
#define DEBUG false
#define N 200005
ll gcd(ll a , ll b) {return b == 0 ? a : gcd(b, a % b);}
ll lcm(ll a, ll b)
{
	return (a / gcd(a, b)) * b;
}

void solve()
{
	ll n;
	cin >> n;
	ll a[n];
	for (ll i = 0; i < n; i++)cin >> a[i];
	cout << 3 * n << "\n";
	for (ll i = 0; i < n; i += 2)
	{
		cout << "1 " << i + 1 << " " << i + 2 << "\n";
		cout << "2 " << i + 1 << " " << i + 2 << "\n";
		cout << "1 " << i + 1 << " " << i + 2 << "\n";
		cout << "2 " << i + 1 << " " << i + 2 << "\n";
		cout << "1 " << i + 1 << " " << i + 2 << "\n";
		cout << "2 " << i + 1 << " " << i + 2 << "\n";
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output3.txt", "w", stdout);
#endif
	ll t = 1;
	cin >> t;
	while (t--)
	{
		solve();
	}
	return 0;
}
