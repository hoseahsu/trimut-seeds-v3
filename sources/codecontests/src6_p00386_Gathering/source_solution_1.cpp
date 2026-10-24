#include <bits/stdc++.h>
using namespace std;

#define INF_LL (int64)1e18
#define INF (int32)1e9
#define REP(i, n) for(int64 i = 0;i < (n);i++)
#define FOR(i, a, b) for(int64 i = (a);i < (b);i++)
#define all(x) x.begin(),x.end()
#define fs first
#define sc second

using int32 = int_fast32_t;
using uint32 = uint_fast32_t;
using int64 = int_fast64_t;
using uint64 = uint_fast64_t;
using PII = pair<int32, int32>;
using PLL = pair<int64, int64>;

const double eps = 1e-10;

template<typename A, typename B>inline void chmin(A &a, B b){if(a > b) a = b;}
template<typename A, typename B>inline void chmax(A &a, B b){if(a < b) a = b;}

int32 N, Q;
vector<PII> G[112345];
int64 dep[112345], dis[112345];
int64 par[112345][20];

void dfs(int32 v=0, int32 p=-1, int32 d=0, int32 x=0){
	dep[v] = d; dis[v] = x;
	par[v][0] = p;
	REP(i, G[v].size()){
		int32 u, di;
		tie(di, u) = G[v][i];
		if(u == p){
			continue;
		}
		dfs(u, v, d+1, x+di);
	}
}

void build(){
	REP(k, 20){
		REP(i, N){
			if(par[i][k] != -1)
				par[i][k+1] = par[par[i][k]][k];
		}
	}
}

int32 lca(int32 u, int32 v){
	if(dep[u] < dep[v]) swap(u, v);
	REP(i, 20){
		if((dep[u]-dep[v]) >> i & 1) u = par[u][i];
	}
	if(u == v) return u;
	for(int32 i = 19;i >= 0;i--){
		if(par[u][i] != -1 && par[u][i] != par[v][i]){
			u = par[u][i];
			v = par[v][i];
		}
	}
	return par[u][0];
}

int64 dist(int32 u, int32 v){
	return dis[u]+dis[v]-2*dis[lca(u, v)];
}

int main(void){
	cin.tie(0);
	ios::sync_with_stdio(false);

	memset(dep, -1, sizeof dep);
	memset(par, -1, sizeof par);
	memset(dis, -1, sizeof dis);
	cin >> N >> Q;
	REP(i, N-1){
		int32 u, v, w;
		cin >> u >> v >> w; u--; v--;
		G[u].push_back(PII(w, v));
		G[v].push_back(PII(w, u));
	}
	dfs();
	build();

	REP(i, Q){
		int32 a, b, c;
		cin >> a >> b >> c; a--; b--; c--;
		PII p(a, b);
		if(dist(b, c) > dist(p.fs, p.sc)) p = PII(b, c);
		if(dist(a, c) > dist(p.fs, p.sc)) p = PII(a, c);
		int64 w = dist(p.fs, p.sc)/2;
		int32 r = lca(p.fs, p.sc);
		if(dis[p.fs] < dis[p.sc]) swap(p.fs, p.sc);
		int32 u = p.fs;
		for(int32 i = 19;i >= 0;i--){
			if(dist(par[u][i], p.fs) < w)
				u = par[u][i];
		}
		int64 res = INF_LL;
		res = min(res, max({dist(u, a), dist(u, b), dist(u, c)}));
		if(par[u][0] != -1){
			u = par[u][0];
			res = min(res, max({dist(u, a), dist(u, b), dist(u, c)}));
		}
		cout << res << endl;
	}
}

