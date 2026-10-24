#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef complex<double> point;
typedef double DOUBLE;
#define xx real()
#define yy imag()

#define REP(i, a, b) for(int i = (a); i < (int)(b); i++)
#define REPN(i, a, b) for(int i = (a); i <= (int)(b); i++)
#define FA(it, x) for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define SZ(x) (int)(x).size()
#define BE(x) (x).begin(), (x).end()
#define SORT(x) sort(BE(x))
#define _1 first
#define _2 second

#define x1 gray_cat_x1
#define y1 gray_cat_y1

template<class T> T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

#define file "I1"

const double EPS = 1e-9;
const double PI = acos(-1.);
const ll LL_INF = 1e17 + 10;
const int INF = 1e9 + 10;
const ll MOD = 1e9 + 7;

const int MAXN = 1e6 + 5;

ll dp[MAXN];
ll f[MAXN], f_sum[MAXN];

void solve(){
	int n, h, d;
	scanf("%d%d%d", &n, &h, &d);
	f[0] = 1, f_sum[0] = 0;
	REPN(i, 1, n) {
		f[i] = (f[i - 1] * i) % MOD;
		f_sum[i] = (f_sum[i - 1] + f[i]) % MOD;
	}
	dp[0] = f[n];
	ll dp_sum = f[n];
	ll ans = 0ll;
	REP(i, 1, h) {
		dp[i] = (dp_sum * f_sum[n]) % MOD;
		dp_sum = (dp_sum + dp[i]) % MOD;
		if (i >= d) {
			dp_sum = (dp_sum + MOD - dp[i - d]) % MOD;
		}
	}
	/*REP(i, 0, h) {
		printf("%lld\n", dp[i]);
	}*/
	cout << dp_sum << endl;
}   

int main(){

    //freopen(file".in", "r", stdin); freopen(file".out", "w", stdout);
    int t = 1;
    //cin >> t;
    while(t--){
        solve();    
    }
}
