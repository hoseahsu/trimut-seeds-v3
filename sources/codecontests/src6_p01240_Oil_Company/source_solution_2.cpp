#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <cassert>
#include <queue>
using namespace std;

using Weight = int;
using Capacity = int;
struct Edge {
	int src, dst; Capacity cap;
	Edge(int s, int d, Capacity c) : src(s), dst(d), cap(c) {}
};
using Edges = vector<Edge>;
using Graph = vector<Edges>;

struct Dinic {
	int n, s, t;
	vector<int> level, prog, que;
	vector<vector<Capacity>> cap, flow;
	vector<vector<int>> g;
	Capacity inf;
	Dinic(const Graph &graph)
		: n(graph.size()),
		cap(n, vector<Capacity>(n)), flow(n, vector<Capacity>(n)),
		g(n, vector<int>()), inf(numeric_limits<Capacity>::max() / 8) {
		for(int i = 0; i < n; i++) {
			for(auto &e : graph[i]) {
				int u = e.src, v = e.dst;
				Capacity c = e.cap;
				cap[u][v] += c; cap[v][u] += c; flow[v][u] += c;
				g[u].push_back(v); g[v].push_back(u);
			}
		}
	}
	inline Capacity residue(int u, int v) { return cap[u][v] - flow[u][v]; }
	Capacity solve(int s_, int t_) {
		this->t = t_, this->s = s_;
		que.resize(n + 1);
		Capacity res = 0;
		while(levelize()) { prog.assign(n, 0); res += augment(s, inf); }
		return res;
	}
	bool levelize() {
		int l = 0, r = 0;
		level.assign(n, -1); level[s] = 0; que[r++] = s;
		while(l != r) {
			int v = que[l++]; if(v == t) break;
			for(const int &d : g[v]) if(level[d] == -1 && residue(v, d) != 0) {
				level[d] = level[v] + 1; que[r++] = d;
			}
		}
		return level[t] != -1;
	}
	Capacity augment(int v, Capacity lim) {
		Capacity res = 0;
		if(v == t) return lim;
		for(int &i = prog[v]; i < (int)g[v].size(); i++) {
			const int &d = g[v][i];
			if(residue(v, d) == 0 || level[v] >= level[d]) continue;
			const Capacity aug = augment(d, min(lim, residue(v, d)));
			flow[v][d] += aug; flow[d][v] -= aug;
			res += aug; lim -= aug;
			if(lim == 0) break;
		}
		return res;
	}
};


int W, H;
int toV(int i, int j) {
	return W * i + j;
}

int dx[4] = { 1, 0, -1, 0 }, dy[4] = { 0, 1, 0, -1 };

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);


	int Test;
	cin >> Test;
	for(int t = 1; t <= Test; t++) {
		cin >> W >> H;
		int r[20][20];
		int sum = 0;
		for(int i = 0; i < H; i++) {
			for(int j = 0; j < W; j++) {
				cin >> r[i][j];
				sum += r[i][j];
			}
		}
		Graph G(H * W + 2);

		int S = H * W, T = S + 1;
		for(int i = 0; i < H; i++) {
			for(int j = 0; j < W; j++) {
				if((i + j) % 2 == 0) {
					G[S].push_back(Edge{ S, toV(i, j), r[i][j] });
					G[toV(i, j)].push_back(Edge{ toV(i, j), T, 0 });
					for(int k = 0; k < 4; k++) {
						int ni = i + dy[k], nj = j + dx[k];
						if(ni < 0 || H <= ni || nj < 0 || W <= nj) continue;
						G[toV(i, j)].push_back(Edge{ toV(i, j), toV(ni, nj), (int)1e9 });
					}
				}
				else {
					G[S].push_back(Edge{ S, toV(i, j), 0 });
					G[toV(i, j)].push_back(Edge{ toV(i, j), T, r[i][j] });
				}
			}
		}

		Dinic dinic(G);
		cout << "Case " << t << ": " << sum - dinic.solve(S, T) << endl;
	}

}