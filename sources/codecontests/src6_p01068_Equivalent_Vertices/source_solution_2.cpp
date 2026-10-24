// * template

#include <bits/stdc++.h>
#ifdef LOCAL
#include "dump.hpp"
#else
#define dump(...)
#endif

using namespace std;

template<class T> inline void chmax(T &a, const T &b) { if(a < b) a = b; }
template<class T> inline void chmin(T &a, const T &b) { if(a > b) a = b; }

template<class T, class U> inline void fill_array(T &e, const U &v) { e = v; }
template<class T, class U, size_t s> inline void fill_array(T (&a)[s], const U &v) {for(auto&e:a)fill_array(e,v);}
template<class T, class U, size_t s> inline void fill_array(array<T, s> &a, const U &v) {for(auto&e:a)fill_array(e,v);}
template<class T, class U> inline void fill_array(vector<T> &a, const U &v) {for(auto&e:a)fill_array(e,v);}

// * solve

int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);

	using Graph = vector<vector<int>>;

	int n, q;
	cin >> n >> q;

	set<int> circle, hexagon;
	array<Graph, 2> rG;
	rG.fill(Graph(n));

	for(int v = 0; v < n; ++v) {
		int kind, zero, one;
		cin >> kind >> zero >> one;

		rG[0][zero].emplace_back(v);
		rG[1][one].emplace_back(v);

		if(kind == 0) {
			circle.emplace(v);
		}
		else {
			hexagon.emplace(v);
		}
	}

	vector<int> idx(n);
	vector<set<int>> S;
	queue<int> que;

	const auto update = [&idx, &S, &que](const set<int> &V) {
		for(const auto &v : V) {
			idx[v] = S.size();
		}
		que.emplace(S.size());
		S.emplace_back(V);
	};

	update(circle);
	update(hexagon);

	while(!que.empty()) {
		const set<int> V = S[que.front()];
		que.pop();

		for(const auto &G : rG) {
			map<int, set<int>> M;

			for(const auto &v : V) {
				for(const auto &u : G[v]) {
					M[idx[u]].emplace(u);
				}
			}

			for(const auto &e : M) {
				const int i = e.first;
				set<int> U = e.second;

				assert(0 <= i && i < S.size());
				if(S[i].size() == U.size()) continue;

				set<int> W;
				for(const auto &v : S[i]) {
					if(!U.count(v)) W.emplace(v);
				}
				update(U);
				update(W);
			}
		}
	}

	while(q--) {
		int v;
		cin >> v;
		cout << S[idx[v]].size() << endl;
	}

	return EXIT_SUCCESS;
}