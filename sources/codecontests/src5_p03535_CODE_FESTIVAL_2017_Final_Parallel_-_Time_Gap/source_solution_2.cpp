#include <bits/stdc++.h>
using namespace std;

typedef class UnionFound {
	public:
		int n;
		int *f;
		int *w;

		void init(int n) {
			this->n = n;
			f = new int[(n + 1)];
			w = new int[(n + 1)];
			for (int i = 0; i <= n; i++) {
				f[i] = i;
			}
			fill(w, w + n + 1, 0);
		}
		
		int find(int x) {
			if (f[x] == x)
				return x;
			int y = f[x];
			f[x] = find(f[x]);
			w[x] ^= w[y];
			return f[x];
		}

		bool unit(int x, int y, int t) {
			int fx = find(x), fy = find(y);
			if (fx == fy) {
				return !(w[x] ^ w[y] ^ t);
			}
			w[fx] = w[x] ^ t;
			f[fx] = y;
			return true;
		}
} UnionFound;

int n;
int a[55];

int gap(int x, int y) {
	if (x > y)
		swap(x, y);
	return min(y - x, 24 - y + x);
}

bool check(int mid) {
	UnionFound uf;
	uf.init(n);
	for (int i = 0; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (gap(a[i], a[j]) < mid) {
				if (gap(a[i], 24 - a[j]) < mid) {
					return false;
				}
				if (!uf.unit(i, j, 1)) {
					return false;
				}
			} else if (gap(a[i], 24 - a[j]) < mid) {
				if (!uf.unit(i, j, 0)) {
					return false;
				}
			}
		}
	}
	return true;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", a + i);
		if (a[i] >= 12) {
			a[i] = 24 - a[i];
		}
	}
	int ans = 0;
	while (check(ans + 1)) {
		ans++;
	}
	printf("%d\n", ans);
	return 0;
}
