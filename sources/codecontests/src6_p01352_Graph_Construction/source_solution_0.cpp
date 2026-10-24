#include <bits/stdc++.h>

// #define set unordered_set
// #define map unordered_map

using namespace std;

class UnionFind {
private:
	int size;
	int parent[40000];
	int rank[40000];

public:
	UnionFind() {}
	UnionFind(int sz) {
		init(sz);
	}
	void init(int sz) {
		size = sz;
		fill(rank, rank+sz, 0);
		for (int i = 0; i < sz; ++i) {
			parent[i] = i;
		}
	}
	int root(int n) {
		if (parent[n] == n) return n;
		return parent[n] = root(parent[n]);
	}
	void unite(int n, int m) {
		int x = root(n);
		int y = root(m);
		if (x == y) return;

		if (rank[x] < rank[y]) {
			parent[x] = y;
		}
		else if (rank[x] > rank[y]) {
			parent[y] = x;
		}
		else {
			parent[x] = y;
			++rank[y];
		}
	}
	bool isUnited(int n, int m) {
		return root(n) == root(m);
	}
};


typedef pair<int, int> P;

struct Query {
	int type, u, v;
};

typedef vector< set<int> > Graph;

const int bucket = 100;

map<int, int> make_table(set<P>& use) {
	map<int, int> res;
	set<int> s;
	for (P p : use) {
		s.insert(p.first);
		s.insert(p.second);
	}
	int n = 0;
	for (int v : s) {
		res[v] = n++;
	}
	return res;
}
Graph trim(Graph& G, set<P>& use, map<int, int>& tbl) {
	tbl = make_table(use);

	int i = 0;
	Graph res(tbl.size());
	UnionFind uf(G.size());
	for (int i = 0; i < G.size(); ++i) {
		for (int v : G[i]) {
			if ( !use.count( P(i, v) ) ) {
				uf.unite(i, v);
			}
		}
	}
	for (P p1 : tbl) {
		for (P p2 : tbl) {
			int a = p1.first, b = p2.first;
			if ( uf.isUnited(a, b) ) {
				tbl[a] = tbl[b];
			}
		}
	}
	for (P p1 : tbl) {
		for (P p2 : tbl) {
			int a = p1.first, b = p2.first;
			if ( G[b].count(a) ) {
				res[tbl[b]].insert(tbl[a]);
			}
		}
	}
	return res;
}
void unite(Graph& G, int u, int v) {
	G[u].insert(v);
	G[v].insert(u);
}
void remove(Graph& G, int u, int v) {
	G[u].erase(v);
	G[v].erase(u);
}
bool judge(Graph& G, int v, int t, vector<bool>& reached) {
	if (v == t) return true;
	reached[v] = true;
	for (int to : G[v]) {
		if ( !reached[to] ) {
			if ( judge(G, to, t, reached) ) return true;
		}
	}
	return false;
}
bool judge(Graph& G, int s, int t) {
	vector<bool> reached(G.size(), false);
	return judge(G, s, t, reached);
}

set<P> Use[40000/bucket+1];
int main() {
	int N, M; cin >> N >> M;
	Query Q[40000];
	for (int i = 0; i < M; ++i) {
		int t, u, v; scanf("%d%d%d", &t, &u, &v);
		Q[i] = (Query){t, u, v};
	}
	for (int i = 0; i < M; ++i) {
		int type = Q[i].type, u = Q[i].u, v = Q[i].v;
		Use[i/bucket].insert( P(u, v) );
		Use[i/bucket].insert( P(v, u) );
	}
	Graph G(N);
	Graph g;
	map<int, int> tbl;
	for (int i = 0; i < M; ++i) {
		int type = Q[i].type, u = Q[i].u, v = Q[i].v;
		if (i % bucket == 0) {
			g = trim(G, Use[i/bucket], tbl);
		}
		switch (type) {
		case 1: // unite
			unite(G, u, v);
			unite(g, tbl[u], tbl[v]);
			break;
		case 2: // remove
			remove(G, u, v);
			remove(g, tbl[u], tbl[v]);
			break;
		case 3: // judge
			if ( judge(g, tbl[u], tbl[v]) ) {
				cout << "YES" << endl;
			}
			else {
				cout << "NO" << endl;
			}
			break;
		}
	}
}