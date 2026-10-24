#include <cstdio>
#include <vector>

const int MN = 100005;

int N;
std::vector<int> G[MN];

int Ans, siz[MN];
void DFS(int u, int p) {
	siz[u] = 1;
	int s = 0;
	for (int v : G[u]) if (v != p) {
		DFS(v, u);
		s += siz[v];
		siz[u] ^= siz[v]; 
	}
	if (s >= 2) Ans = 1;
}

int main() {
	scanf("%d", &N);
	if (N & 1) return puts("First"), 0;
	for (int i = 1, x, y; i < N; ++i) {
		scanf("%d%d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	DFS(1, 0);
	puts(Ans ? "First" : "Second");
	return 0;
}