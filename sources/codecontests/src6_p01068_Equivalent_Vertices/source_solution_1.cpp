#include<bits/stdc++.h>

#define rep(i,n) for(int i=0;i<(int)n;i++)
#define all(c) (c).begin(),(c).end()
#define mp make_pair
#define pb push_back
#define each(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)
#define dbg(x) cerr<<__LINE__<<": "<<#x<<" = "<<(x)<<endl

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
const int inf = (int)1e9;
const double INF = 1e12, EPS = 1e-9;

int n, m, v[3000], s[3000], t[3000];

int main(){
	cin >> n >> m;
	rep(i, n) cin >> v[i] >> s[i] >> t[i];
	rep(it, n){
		vector<ll> x;
		vi next;
		rep(i, n) x.pb(v[i] * (ll)1e9 + v[s[i]] * 10000 + v[t[i]]);
		sort(all(x)); x.erase(unique(all(x)), x.end());
		rep(i, n) next.pb(lower_bound(all(x), v[i] * (ll)1e9 + v[s[i]] * 10000 + v[t[i]]) - x.begin());
		rep(i, n) v[i] = next[i];
	}
	unordered_map<int, int> cnt;
	rep(i, n) cnt[v[i]]++;
	rep(i, m){
		int q; cin >> q;
		cout << cnt[v[q]] << endl;
	}
	return 0;
}