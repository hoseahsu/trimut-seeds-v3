#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const int N = 310;
const int Mod = 1e9 + 7;
int n, m, f[N][N][N];

inline int dec(int x) {return x < 0 ? x + Mod : x;}
inline int inc(int x) {return x >= Mod ? x - Mod : x;}

int main() {
	cin >> n >> m;
	f[0][1][1] = 1;
	for (int i = 0; i < m; ++i)
		for (int j = 1; j <= i + 1 && j <= n; ++j)
			for (int k = 0; k <= j; ++k) if (f[i][j][k]) {
				f[i + 1][j + 1][k] = inc(f[i + 1][j + 1][k] + 1LL * f[i][j][k] * (n - j) % Mod);
				f[i + 1][j][k] = inc(f[i + 1][j][k] + 1LL * f[i][j][k] * (j - k) % Mod);
				f[i + 1][j][j] = inc(f[i + 1][j][j] + 1LL * f[i][j][k] * k % Mod);
			}
	cout << f[m][n][n];
	return 0;
}