#include <bits/stdc++.h>
#define EB emplace_back

typedef std::vector <int> vector;
const int N = 300054;

int n, R;
int x[N];
vector left[N];

int sum(int h) {int s = 0; for (; h; h &= h - 1) s += x[h]; return s;}
void add(int h, int v) {for (; h <= R; h |= h - 1, ++h) x[h] += v;}

int main() {
	int i, j, l, r, ans;
	scanf("%d%d", &n, &R);
	for (i = 0; i < n; ++i) scanf("%d%d", &l, &r), left[r - l + 1].EB(l);
	for (i = 1; i <= R; ++i) {
		for (ans = n, j = i; j <= R; j += i) ans += sum(j);
		printf("%d\n", ans);
		for (int le : left[i]) add(le, 1), add(le + i, -1), --n;
	}
	return 0;
}