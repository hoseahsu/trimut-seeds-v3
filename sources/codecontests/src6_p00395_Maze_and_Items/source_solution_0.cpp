#include <iostream>
#include <queue>
using namespace std;

int H, W, sx[32], sy[32], s[10][10], idx[1009][1009];
char c[1009][1009];
int t[32][32], u[1009][1009];
pair<int, int> dp[1 << 10][32];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main() {
	cin >> W >> H;
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			cin >> c[i][j]; idx[i][j] = -1;
			if (c[i][j] == 'S') { sx[30] = i; sy[30] = j; }
			if (c[i][j] == 'T') { sx[31] = i; sy[31] = j; }
			if (c[i][j] >= '0' && c[i][j] <= '9') {
				sx[0 + (c[i][j] - '0')] = i;
				sy[0 + (c[i][j] - '0')] = j;
			}
			if (c[i][j] >= 'A' && c[i][j] <= 'J') {
				sx[10 + (c[i][j] - 'A')] = i;
				sy[10 + (c[i][j] - 'A')] = j;
			}
			if (c[i][j] >= 'a' && c[i][j] <= 'z') {
				sx[20 + (c[i][j] - 'a')] = i;
				sy[20 + (c[i][j] - 'a')] = j;
			}
		}
	}
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) cin >> s[i][j];
	}
	for (int i = 0; i <= 31; i++) { idx[sx[i]][sy[i]] = i; for (int j = 0; j <= 31; j++) t[i][j] = (1 << 25); }

	for (int i = 0; i <= 31; i++) {
		if (sx[i] == 0 && sy[i] == 0) continue;
		for (int j = 1; j <= H; j++) { for (int k = 1; k <= W; k++) u[j][k] = (1 << 25); }

		queue<pair<int, int>> Q;
		Q.push(make_pair(sx[i], sy[i]));
		u[sx[i]][sy[i]] = 0;

		while (!Q.empty()) {
			int cx = Q.front().first, cy = Q.front().second; Q.pop();

			for (int j = 0; j < 4; j++) {
				int ex = cx + dx[j], ey = cy + dy[j];
				if (ex <= 0 || ey <= 0 || ex > H || ey > W || c[ex][ey] == '#') continue;

				if (idx[ex][ey] == -1) {
					if (u[ex][ey] == (1 << 25)) {
						Q.push(make_pair(ex, ey));
						u[ex][ey] = u[cx][cy] + 1;
					}
				}
				else {
					t[i][idx[ex][ey]] = min(t[i][idx[ex][ey]], u[cx][cy] + 1);
				}
			}
		}
	}

	for (int i = 0; i < (1 << 10); i++) {
		for (int j = 0; j < 32; j++) dp[i][j] = make_pair((1 << 25), (1 << 25));
	}
	dp[0][30] = make_pair(0, 0);

	pair<int, int> maxn = make_pair((1 << 25), -1);

	for (int i = 0; i < (1 << 10); i++) {
		for (int j = 0; j < 32; j++) {
			if (dp[i][j] == make_pair((1 << 25), (1 << 25))) continue;

			// 幅優先探索
			int dist[32]; for (int k = 0; k < 32; k++) dist[k] = (1 << 25); dist[j] = 0;
			vector<int> V;
			for (int k = 0; k < 10; k++) V.push_back(k);
			for (int k = 0; k < 10; k++) { if ((i / (1 << k)) % 2 == 0) V.push_back(10 + k); }
			for (int k = 0; k < 10; k++) { if ((i / (1 << k)) % 2 == 1) V.push_back(20 + k); }
			V.push_back(30); V.push_back(31);

			for (int tt = 0; tt < 22; tt++) {
				for (int k : V) {
					for (int l : V) {
						if (t[k][l] == -(1 << 25)) continue;
						dist[l] = min(dist[l], dist[k] + t[k][l]);
					}
				}
			}

			if (i == 1023) {
				maxn = min(maxn, make_pair(dp[i][j].first + dist[31], dp[i][j].second));
			}

			// DP の更新
			for (int k = 0; k < 10; k++) {
				if (dist[k] == (1 << 25) || (i / (1 << k)) % 2 == 1) continue;
				dp[i + (1 << k)][k] = min(dp[i + (1 << k)][k], make_pair(dp[i][j].first + dist[k], dp[i][j].second - s[j][k]));
			}
		}
	}

	if (maxn.first == (1 << 25)) cout << "-1" << endl;
	else cout << maxn.first << " " << -maxn.second << endl;
	return 0;
}
