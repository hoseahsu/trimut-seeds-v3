#include <bits/stdc++.h>

using namespace std;

#define REP(i,n) for(ll (i) = (0);(i) < (n);++i)
#define REV(i,n) for(ll (i) = (n) - 1;(i) >= 0;--i)
#define PB push_back
#define EB emplace_back
#define MP make_pair
#define FI first
#define SE second
#define SHOW1d(v,n) {REP(WW,n)cerr << v[WW] << ' ';cerr << endl << endl;}
#define SHOW2d(v,WW,HH) {REP(W_,WW){REP(H_,HH)cerr << v[W_][H_] << ' ';cerr << endl;}cerr << endl;}
#define ALL(v) v.begin(),v.end()
#define Decimal fixed<<setprecision(20)
#define INF 1000000000
#define LLINF 1000000000000000000LL
#define MOD 998244353
#define fastcin() cin.tie(0);ios::sync_with_stdio(false)

typedef long long ll;
typedef pair<ll,ll> P;

ll n, q, k ,d;
vector<set<P>> s(61);
void build(ll target) {
	//cout << "dfs " << target << endl;
	s[0].insert(MP(target, target + 1));
	REP(i, 60){
		for(auto it = s[i].begin();it != s[i].end();){
			P p= *it;
			it++;
			while(it != s[i].end() && it -> FI <= p.SE){
				p.SE = max(p.SE, it -> SE);
				it++;
			}
			{
				ll l=p.first,r=min(p.second,n/2)-1;
				if(l <= r)s[i+1].insert(P(2*(l%(n/2)),2*(r%(n/2))+2));
			}
			{
				ll l=max(p.first,n/2),r=min(p.second,n)-1;
				if(l <= r)s[i+1].insert(P(2*(l%(n/2)),2*(r%(n/2))+2));
			}
		}
	}
}

int main(){

	cin >> n >> q >> k >> d;
	d--;k--;
	build(d);
	//cout << "out build" << endl;
	vector<int> ans;

	for(int i = q;i > 0;i--){
		//cout << "k " << k << endl;
		if(i > 60){
			if(k % 2)ans.PB(1);
			else ans.PB(0);
			k /= 2;
		}
		else {
			bool ok = false;
			ll a = (k / 2);
			ll b = (k / 2) + n / 2;
			//cout << "ab " << a << " " << b << endl;
			for(auto it = s[i-1].begin();it != s[i-1].end();it++){
				if(it -> FI <= a && a < it -> SE){
					if(k%2)ans.PB(1);
					else ans.PB(0);
					k = a;
					ok = true;
					break;
				}
				if(it -> FI <= b && b < it -> SE){
					if(k%2)ans.PB(0);
					else ans.PB(1);
					k = b;
					ok = true;
					break;
				}
			}
			if(!ok){
				cout << -1 << endl;
				return 0;
			}
		}
	}

	REP(i,q)cout << ans[i] << endl;


	return 0;
}

