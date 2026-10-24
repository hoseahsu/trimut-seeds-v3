#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<utility>
#include<map>
using namespace std;
typedef long long ll;
const ll mod = 1000000007;
const ll INF = mod * mod;
typedef pair<ll, ll> P;

#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define all(x) (x).begin(),(x).end()
#define stop char nyaa; cin>>nyaa;

ll sum[100001][300];
ll truesum[100000][300];
int sz = 300;
ll t10[19];


int lenq(ll a, ll b) {
	return upper_bound(t10, t10 + 19, a*b)-t10;
}
void solve() {
	t10[0] = 1;
	rep(i, 18) {
		t10[i + 1] = t10[i] * 10;
	}
	int n, m; cin >> n >> m;
	vector<ll> a(n);
	vector<ll> b(m);
	rep(i, n) {
		cin >> a[i];
	}
	rep(i, m) {
		cin >> b[i];
	}
	vector<int> x;
	rep(i, n)x.push_back(a[i]);
	sort(x.begin(), x.end());
	x.erase(unique(x.begin(), x.end()), x.end());
	int di = (m + sz - 1) / sz;
	rep(i, m) {
		ll s = b[i];
		int le = 0;
		int loc = i / di;
		rep1(j, 18) {
			int id = lower_bound(x.begin(), x.end(), (t10[j]+s-1) / s) - x.begin();
			sum[le][loc] += j;
			sum[id][loc] -= j;
			le = id;
		}
			sum[le][loc] += 19;
			sum[x.size()][loc] -= 19;
	}
	rep(i, x.size()) {
		rep(j, sz) {
			sum[i + 1][j] += sum[i][j];
		}
	}
	vector<ll> alsum(n, 0);
	rep(i, n) {
		int id = lower_bound(x.begin(), x.end(), a[i]) - x.begin();
		rep(j, sz) {
			truesum[i][j] = sum[id][j];
			alsum[i] += truesum[i][j];
		}
	}
	vector<ll> allsum(n + 1, 0);
	rep(i, n) {
		allsum[i + 1] = allsum[i] + alsum[i];
	}
	/*rep(i, n + 1) {
		cout << "! " << allsum[i] << endl;
	}*/
	string ans;
	int q; cin >> q;
	//cout << allsum[n] << endl;
	rep(aa, q) {
		ll x; cin >> x; x--;
		if (x >= allsum[n]) {
			//cout << 'x'; 
			ans.push_back('x');
			continue;
		}
		int rw = upper_bound(allsum.begin(), allsum.end(), x) - allsum.begin();
		rw--;
		ll rest = x - allsum[rw];
		int loc = rw;
		int chk = sz - 1;
		rep(j, sz) {
			if (truesum[loc][j] <= rest) {
				rest -= truesum[loc][j];
			}
			else {
				chk = j; break;
			}
		}
		int sta = di * chk;
		while (true) {
			//cout << loc << " " << sta << " "<<rest<<endl;
			int len = lenq(a[loc], b[sta]);
			if (len > rest) {
				string st = to_string(a[loc] * b[sta]);
				//cout << st[rest];
				ans.push_back(st[rest]);
				break;
			}
			else {
				rest -= len;
				sta++;
			}
		}

	}
	cout << ans<<endl;
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	//find_prime();
	solve();
	//stop
		return 0;
}
