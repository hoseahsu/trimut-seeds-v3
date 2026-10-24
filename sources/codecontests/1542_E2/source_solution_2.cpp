#undef local
//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define all(v) v.begin(),v.end()
#define allr(v) v.rbegin(),v.rend()
#define fori(i,n) for(ll i=0;i<n;i++)
#define ford(i,n) for(ll i = n-1;i >= 0;i--)
#define pb push_back
#define ll long long int
//#define mod 998244353
#define pi pair<int,int>
#define pll pair<ll,ll>
#define mp make_pair
#define fi first
#define se second
#ifdef local
#define debug(x) cout<<#x<<" = "<<x<<endl
#define debug2(x,y) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<endl
#define debug3(x,y,z) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<endl
#define debug4(x,y,z,q) cout<<#x<<" = "<<x<<", "<<#y<<" = "<<y<<", "<<#z<<" = "<<z<<", "<<#q<<" = "<<q<<endl
#define debugV(v) cout <<#v<<" = ";fori(i,(int) v.size()) {cout << v[i] << " ";} cout << endl << endl;
#define printVector(v) {fori(i,(int) v.size()) {cout << v[i] << " ";} cout << "\n";}
#else
#define debug(x) 1
#define debug2(x,y) 1
#define debug3(x,y,z) 1
#define debug4(x,y,z,q) 1
#define debugV(v) 1
#define printVector(v) {fori(i,(int) v.size()) {cout << v[i] << " ";} cout << "\n";}
#endif
std::mt19937 rng((unsigned int) std::chrono::steady_clock::now().time_since_epoch().count());
using namespace std;
void solve(int ttt)
{
	ll n,mod;
	cin >> n >> mod;
	int T = n*(n-1)+1;
	ll * withDiff = new ll[T],*pref = new ll[T];
	ll * nwithDiff = new ll[T],*npref = new ll[T];
	memset(withDiff,0,sizeof(ll)*T);
	memset(pref,0,sizeof(ll)*T);
	auto get = [&](int l,int r,ll * v)
	{
		r = min(r,T-1);
		l = max(l,0);
		if(l > r) return 0LL;
		ll res = v[r];
		if(l > 0) res -= v[l-1];
		res += mod;
		res %= mod;
		return res;
	};
	int offset = (n*(n-1))/2;
	withDiff[0+offset] = 1;
	for(int k = 0;k <= n*(n-1);k++)
	{
		pref[k] += withDiff[k];
		if(k) pref[k] += pref[k-1];
		pref[k] %= mod;
	}
	vector<ll> ans(n+1,0);
	for(int i = 2;i <= n;i++)
	{
		memset(nwithDiff,0,sizeof(ll)*T);
		memset(npref,0,sizeof(ll)*T);
		ll res = 0;
		int d = -(i*(i-1))/2;
		int dd = d + offset;
		nwithDiff[dd] = 1;
		d++;
		for(;d <= (i*(i-1)/2);d++)
		{
			res = 0;
			int dd = d + offset;
			res += nwithDiff[dd-1] - get(dd-1-(i-1),dd-1,pref) + get(dd,dd+i-1,pref);
			res += mod;
			res %= mod;
			nwithDiff[dd] = res;
		}
		for(int k = 0;k <= n*(n-1);k++)
		{
			npref[k] = nwithDiff[k];
			if(k) npref[k] += npref[k-1];
			npref[k] %= mod;
		}
		{
			ll res = 0;
			for(int d = 1;d < i;d++)
			{
					int dd = d+1 + offset;
					if(dd <= n*(n-1))
					res += (get(dd,n*(n-1),pref)*(i-d))%mod;
					res %= mod;
			}
			res += (ans[i-1] * (i))%mod;
			res %= mod;
			ans[i] = res;
		}
		swap(withDiff,nwithDiff);
		swap(pref,npref);
	}
	debug(clock());
	cout << ans[n] << "\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int ttt;
    ttt = 1;
    //cin >> ttt;
    fori(i,ttt) solve(i);
}
