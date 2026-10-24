#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
const long long inf = 1LL << 60;
struct edge {
	int to; long long cost;
};
struct state {
	int pos; long long cost;
};
bool operator<(const state& s1, const state& s2) {
	return s1.cost > s2.cost;
}
int main() {
	int N, M;
	cin >> N >> M;
	vector<vector<edge> > G(N);
	for (int i = 0; i < M; ++i) {
		int L, R, C;
		cin >> L >> R >> C; --L, --R;
		G[L].push_back(edge{ R, C });
	}
	for (int i = 1; i < N; ++i) {
		G[i].push_back(edge{ i - 1, 0 });
	}
	vector<long long> dist(N, inf);
	dist[0] = 0;
	priority_queue<state> que;
	que.push(state{ 0, 0 });
	vector<bool> vis(N);
	while (!que.empty()) {
		int pos = que.top().pos; que.pop();
		if (vis[pos]) continue;
		vis[pos] = true;
		for (edge e : G[pos]) {
			if (dist[e.to] > dist[pos] + e.cost) {
				dist[e.to] = dist[pos] + e.cost;
				que.push(state{ e.to, dist[e.to] });
			}
		}
	}
	cout << (dist[N - 1] == inf ? -1 : dist[N - 1]) << endl;
	return 0;
}