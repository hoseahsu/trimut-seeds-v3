#include "bits/stdc++.h"
using namespace std;
#ifdef _DEBUG
#include "dump.hpp"
#else
#define dump(...)
#endif

//#define int long long
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(c) begin(c),end(c)
const int INF = sizeof(int) == sizeof(long long) ? 0x3f3f3f3f3f3f3f3fLL : 0x3f3f3f3f;
const int MOD = (int)(1e9) + 7;
template<class T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
template<class T> bool chmin(T &a, const T &b) { if (b < a) { a = b; return true; } return false; }

struct MinimumCostFlow {
	using Flow = int;
	using Cost = double;
	const Cost kInfCost = INF;
	struct Edge {
		int to, rev;
		Flow cap;
		Cost cost;
		Edge() {}
		Edge(int to, int rev, Flow cap, Cost cost) :to(to), rev(rev), cap(cap), cost(cost) {}
	};
	int n;
	vector<vector<Edge>> g;
	vector<Cost> dist;
	vector<int> prevv, preve;
	MinimumCostFlow(int n) :n(n), g(n), dist(n), prevv(n), preve(n) {}
	void addArc(int from, int to, Flow cap, Cost cost) {
		g[from].emplace_back(to, (int)g[to].size(), cap, cost);
		g[to].emplace_back(from, (int)g[from].size() - 1, Flow(), -cost);
	}
	// s??????t????????????f???????°??????¨???
	// ??????????????´?????? kInfCost
	Cost minimumCostFlow(int s, int t, Flow f) {
		Cost total = Cost();
		while (f > 0) {
			// Bellman-Ford
			fill(dist.begin(), dist.end(), kInfCost);
			dist[s] = 0;
			bool update = true;
			while (update) {
				update = false;
				for (int v = 0; v < n; v++) {
					if (dist[v] == kInfCost)continue;
					for (int i = 0; i < g[v].size(); i++) {
						Edge &e = g[v][i];
						if (e.cap > Flow() && dist[e.to] > dist[v] + e.cost) {
							dist[e.to] = dist[v] + e.cost;
							prevv[e.to] = v;
							preve[e.to] = i;
							update = true;
						}
					}
				}
			}
			// ????????\???????????????
			if (dist[t] == kInfCost)
				return kInfCost;
			// ?????????????????£??????????????????
			Flow d = f;
			for (int v = t; v != s; v = prevv[v])
				d = min(d, g[prevv[v]][preve[v]].cap);
			f -= d;
			total += dist[t] * d;
			for (int v = t; v != s; v = prevv[v]) {
				Edge &e = g[prevv[v]][preve[v]];
				e.cap -= d;
				g[v][e.rev].cap += d;
			}
		}
		return total;
	}
};

template<class T, class ...Tail>
void tiedSort(vector<T> &a, vector<Tail>&... tail) {
	int n = a.size();
	using S = tuple<T, Tail...>;
	vector<S> s(n);
	for (int i = 0; i < n; i++)
		s[i] = make_tuple(a[i], tail[i]...);
	sort(s.begin(), s.end());
	for (int i = 0; i < n; i++)
		tie(a[i], tail[i]...) = s[i];
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(10);
	for (int N, K; cin >> N >> K&&N;) {
		vector<int> x(N), y(N), z(N); rep(i, 0, N) {
			cin >> x[i] >> y[i] >> z[i];
		}
		MinimumCostFlow mcf(N + N + 2);
		int s = mcf.n - 2, t = s + 1;
		auto distance = [&](int i, int j) {
			return sqrt((x[i] - x[j])*(x[i] - x[j]) + (y[i] - y[j])*(y[i] - y[j]) + (z[i] - z[j])*(z[i] - z[j]));
		};
		tiedSort(z, x, y);
		rep(i, 0, N)rep(j, 0, i) {
			if (z[i] != z[j])
				mcf.addArc(i, j + N, 1, distance(i, j));
		}
		rep(i, 0, N) {
			mcf.addArc(s, i, 1, 0);
			mcf.addArc(i + N, t, 1, 0);
		}
		auto res = mcf.minimumCostFlow(s, t, max(0, N - K));
		cout << (res == mcf.kInfCost ? -1 : res) << endl;
	}
	return 0;
}