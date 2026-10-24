#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cfloat>
#include <climits>
#include <cstring>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; double w; };

ll MOD = 1000000007;
ll _MOD = 1000000009;
double EPS = 1e-10;
int INF = INT_MAX / 100;

void dijkstra(int n, vector< vector<edge> >& G, int s, vector<double>& d) {
    fill(d.begin(), d.end(), DBL_MAX); d[s] = 0;
    priority_queue<d_i, vector<d_i>, greater<d_i> > q;
    q.push(d_i(0, s));
    while (!q.empty()) {
        d_i p = q.top(); q.pop();
        int u = p.second;
        if (p.first > d[u]) continue;
        for (int i = 0; i < G[u].size(); i++) {
            edge e = G[u][i];
            if (d[e.v] > d[u] + e.w) {
                d[e.v] = d[u] + e.w;
                q.push(d_i(d[e.v], e.v));
            }
        }
    }
}

void add_edge(vector< vector<edge> >& G, int u, int v, double w) {
	edge e = {u, v, w};
	G[u].push_back(e);
}

int f(int n, int x, int y, int v) {
	return (n * x + y) * 32 + v;
}

int main() {
	for (;;) {
		int n, m; cin >> n >> m;
		if (n == 0) break;
		n++;
		int s, g; cin >> s >> g;
		vector< vector<edge> > G(n * n * 32);
		while (m--) {
			int x, y, c; double d;
			cin >> x >> y >> d >> c;
			for (int z = 0; z < n; z++) {
				if (z == x || z == y) continue;
				for (int v = 1; v <= c; v++) {
					add_edge(G, f(n, z, x, v), f(n, x, y, v - 1), d / v);
					add_edge(G, f(n, z, x, v), f(n, x, y, v), d / v);
					add_edge(G, f(n, z, x, v), f(n, x, y, v + 1), d / v);
					add_edge(G, f(n, z, y, v), f(n, y, x, v - 1), d / v);
					add_edge(G, f(n, z, y, v), f(n, y, x, v), d / v);
					add_edge(G, f(n, z, y, v), f(n, y, x, v + 1), d / v);
				}
			}
		}
		vector<double> d(n * n * 32);
		dijkstra(n * n * 32, G, f(n, 0, s, 1), d);
		double mini = DBL_MAX;
		for (int i = 0; i < n; i++)
			mini = min(mini, d[f(n, i, g, 0)]);
		if (mini < DBL_MAX) printf("%.10f\n", mini);
		else cout << "unreachable" << endl;
	}
}