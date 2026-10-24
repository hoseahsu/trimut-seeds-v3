#include<iostream>
#include<algorithm>
using namespace std;
int dp[100][65536], c[30][16], d[30][16];
int n, m, p[16], q[16];
int _count() { int cnt2 = 0; for (int i = 0; i < 16; i++) { cnt2 += q[i] * (1 << i); }return cnt2; }
int main() {
	while (true) {
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 65536; j++) {
				dp[i][j] = -1; c[i % 30][j % 16] = 0; d[i % 30][j % 16] = 0;
			}
		}
		cin >> n >> m; int cnt = 0; if (n == 0 && m == 0) { break; }
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 16; j++) { cin >> c[i][j]; }
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < 16; j++) { cin >> d[i][j]; }
		}
		for (int i = 0; i < n; i++) { cnt += c[0][i] * (1 << i); }
		dp[0][0] = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < 65536; j++) {
				if (dp[i][j] == -1) { continue; }
				for (int k = 0; k < 16; k++) { p[k] = (j / (1 << k)) % 2; }
				for (int k = 0; k < 16; k++) { if (c[i][k] == 1) { p[k] = 1; } }
				for (int k = 0; k < m; k++) {
					for (int l = 0; l < 16; l++) { q[l] = p[l]; }cnt = 0;
					for (int l = 0; l < 16; l++) {
						if (d[k][l] == 1) {
							if (q[l] == 1) { cnt++; } 
							q[l] = 0;
						}
					}
					dp[i + 1][_count()] = max(dp[i + 1][_count()], dp[i][j] + cnt);
				}
			}
		}
		int minx = 0; for (int i = 0; i < 65536; i++) { minx = max(minx, dp[n][i]); }
		cout << minx << endl;
	}
}