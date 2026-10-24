#include <bits/stdc++.h>
using namespace std;
#define at(a, b) get<b>(a)
typedef pair<int, int> PR;
typedef tuple<int, int, int> TP;
const int INF = 1 << 28;

int N, M, L, K, A, H;
vector<PR> g[100];
int dist[100][101];
bool ice[100];

void addEdge(int a, int b, int t)
{
	g[a].push_back(PR(b, t));
	g[b].push_back(PR(a, t));
}

void solve()
{
	fill_n(*dist, 100 * 101, INF);
	dist[A][M] = 0;
	priority_queue<TP, vector<TP>, greater<TP>> pq;
	pq.push(TP(0, A, M));
	while (pq.size()){
		TP t = pq.top(); pq.pop();
		int sum = at(t, 0);
		int pos = at(t, 1);
		int s = at(t, 2);
		if (dist[pos][s] < sum) continue;
		for (int i = 0; i < g[pos].size(); i++){
			int to = g[pos][i].first;
			int cost = g[pos][i].second;
			int ns = s - cost;
			if (ns < 0) continue;
			if (dist[to][ns] <= sum + cost) continue;
			dist[to][ns] = sum + cost;
			pq.push(TP(sum + cost, to, ns));
		}
		if (!ice[pos]) continue;
		for (int i = 1, ns; (ns = s + i) <= M; i++){
			if (dist[pos][ns] <= sum + i) continue;
			dist[pos][ns] = sum + i;
			pq.push(TP(sum + i, pos, ns));
		}
	}
	int res = INF;
	for (int i = 0; i <= M; i++){
		res = min(res, dist[H][i]);
	}
	if (res == INF) puts("Help!");
	else printf("%d\n", res);
}

int main()
{
	while (scanf("%d %d %d %d %d %d", &N, &M, &L, &K, &A, &H), N){
		fill_n(g, 100, vector<PR>());
		fill_n(ice, 100, false);
		ice[A] = ice[H] = true;
		for (int i = 0; i < L; i++){
			int a;
			scanf("%d", &a);
			ice[a] = true;
		}
		for (int i = 0; i < K; i++){
			int x, y, t;
			scanf("%d %d %d", &x, &y, &t);
			addEdge(x, y, t);
		}
		solve();
	}
}