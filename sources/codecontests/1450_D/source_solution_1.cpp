/*  /$$                                     /$$
      | $$                                    | $$
  /$$$$$$$  /$$$$$$   /$$$$$$$  /$$$$$$   /$$$$$$$  /$$$$$$   /$$$$$$
 /$$__  $$ /$$__  $$ /$$_____/ /$$__  $$ /$$__  $$ /$$__  $$ /$$__  $$
| $$  | $$| $$$$$$$$| $$      | $$  \ $$| $$  | $$| $$$$$$$$| $$  \__/
| $$  | $$| $$_____/| $$      | $$  | $$| $$  | $$| $$_____/| $$
|  $$$$$$$|  $$$$$$$|  $$$$$$$|  $$$$$$/|  $$$$$$$|  $$$$$$$| $$
 \_______/ \_______/ \_______/ \______/  \_______/ \_______/|__//$$$$$$ /$$$$$$
                                                               |______/|______/

*/
#include <vector>
#include <list>
#include <map>
#include <climits>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <queue>
#include <unordered_map>
#define fastio        ios_base::sync_with_stdio(false); cin.tie(NULL);
#define ln            cout << endl;
#define vi            vector<int>
#define vll           vector<long long>
#define sortl(vec)    sort(vec.begin(), vec.end());
#define sortr(vec)    sort(vec.rbegin(), vec.rend());
#define forn(i, x, n) for(long long i = x; i < n; i++)
#define revn(i, n, x) for(long long i = n; i >= x; i--)
#define in(vec)       for(auto &it : vec) cin >> it;
#define	out(vec)      for(auto &it : vec) cout << it << " "; ln
#define ll            long long
#define pb            emplace_back
#define mp            make_pair
#define um            unordered_map
#define pii           pair<int, int>
#define pll           pair<ll, ll>
#define ff            first
#define ss            second
#define pi            3.14159265359
#define o(x)          cout << x << endl;
#define oo(x)		  cout << x << endl; return;
#define all(a)        a.begin(), a.end()
#define sz(a)         (ll)a.size()
#define endl          "\n"
#define CLOCK         cerr<<"time taken : "<<(float)clock()/CLOCKS_PER_SEC<<" secs"<<endl;
using namespace std;

const ll Nfact = 200005;
const ll mod = 1000000007;
const ll Nsieve = 1000005;
//https://codeforces.com/blog/entry/74640?#comment-587521

vector<bool> is_prime(Nsieve, true);
vll spf(Nsieve); //Vector to store the smallest prime factor of a number <= Nsieve
void sieve() {
	forn(i, 1, Nsieve + 1) {
		spf[i] = i;
	}
	is_prime[0] = is_prime[1] = false;
	for (ll i = 2; i * i <= Nsieve; i++) {
		if (is_prime[i]) {
			for (ll j = i * i; j <= Nsieve; j += i) {
				if (is_prime[j])
					spf[j] = i;
				is_prime[j] = false;
			}
		}
	}
}
//Proof: https://www.youtube.com/watch?v=pKvGYOnO9Ao(above algorithm)
//For generating all divisors of a number
void divisors(vector<ll>& divs, ll x) {
	//sieve();
	map<ll, ll> mappy;
	while (x != 1) {
		mappy[spf[x]]++;
		x /= spf[x];
	}
	divs.clear();
	divs.push_back(1);
	for (auto p : mappy) {
		ll len = divs.size();
		forn(q, 0, len * p.ss) {
			divs.push_back(divs[q] * p.ff);
		}
	}
	//out(divs)
	sort(divs.begin() , divs.end());
}

ll bSearch(ll l, ll r, ll x, vll arr) {
	while (l <= r) {
		ll m = l + (r - l) / 2;

		if (arr[m] == x)
			return m;

		if (arr[m] < x)
			l = m + 1;

		else
			r = m - 1;
	}

	return -1;
}
//For printing prime factors of a number
void primeFactors(ll n) {
	while (n % 2 == 0) {
		//cout << 2 << " ";
		n = n / 2;
	}

	for (ll i = 3; i <= sqrt(n); i += 2) {
		while (n % i == 0) {
			//cout << i << " ";
			n = n / i;
		}
	}

	if (n > 2)
		cout << n << " ";
}

ll power(ll x, ll y, ll p) {
	ll res = 1;
	x = x % p;

	while (y > 0) {
		if (y & 1)
			res = (res * x) % p;

		y = y >> 1;
		x = (x * x) % p;
	}
	return res;
}

ll modulo(ll a, ll b) {
	ll c = a % b;
	return (c < 0) ? c + b : c;
}

//Use these functions below only when modulus is involved
ll mul(ll x, ll y) {
	return (x * y) % mod;
}

ll inv(ll x) {
	return power(x, mod - 2, mod);
}

ll divide(ll x, ll y) {

	return mul(x, inv(y));
}

ll fact[Nfact];
void precalc() { // Call this once in main()
	fact[0] = 1;
	for (ll i = 1; i < Nfact; i++)
		fact[i] = mul(fact[i - 1], i);
}

ll nCr(ll n, ll k) {
	if (n < k)
		return 0;
	return divide(fact[n], mul(fact[k], fact[n - k]));
}
/****BE CAREFUL****/
//If you
//	 are using
//		 global variables,
//				then clear
//					 them first,
//					      only upto
//						       'n' incase
//							 	   of multiple test-cases

void solve() {
	//If the problem is an interactive one then remove the endl macro.
	//[IMPORTANT] Make the indexing 0-based if required.
	//If using nCr, then call precalc()
	ll n;
	cin >> n;
	vll vec(n);
	in(vec)
	vll left(n), right(n);
	stack<ll>s;
	s.push(0);

	forn(i, 1, n) {
		if (vec[i] < vec[s.top()]) {
			//o(i)
			while (!s.empty() && vec[s.top()] > vec[i])  {
				right[s.top()] = i;
				s.pop();
			}
		}
		s.push(i);
	}
	while (!s.empty()) {
		right[s.top()] = n;
		s.pop();
	}
	s.push(n - 1);
	revn(i, n - 2, 0) {
		if (vec[i] < vec[s.top()]) {
			//o(i)
			while (!s.empty() && vec[s.top()] > vec[i])  {
				left[s.top()] = i;
				s.pop();
			}
		}
		s.push(i);
	}
	while (!s.empty()) {
		left[s.top()] = -1;
		s.pop();
	}
	//out(left)
	map<ll, ll>hash;
	forn(i, 1, n + 1) {
		hash[i] = 0;
	}
	forn(i, 0, n) {
		hash[vec[i]] = max(hash[vec[i]], right[i] - left[i] - 1);
	}
	string ans = string(n, '0');
	vll suffix(n + 1);
	for (auto i : hash) {
		suffix[min(i.ss, n - i.ff + 1)]++;
	}
	revn(i, n - 1, 1) {
		suffix[i] += suffix[i + 1];
	}
	revn(i, n, 1) {
		if (hash[n + 1 - i] >= i && suffix[i] >= n + 1 - i) {
			ans[i - 1] = '1';
		}
	}
	o(ans)
}

int main() {
// in(vec) works for size-defined type vectors

#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input1.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output1.txt", "w", stdout);
#endif

	fastio
	ll t;
	cin >> t;
	while (t--) {
		solve();
	}
	CLOCK
	return 0;
}

     		  	 			  	  		 					 			