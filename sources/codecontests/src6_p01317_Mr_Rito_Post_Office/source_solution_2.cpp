#include <bits/stdc++.h>
using namespace std;

#define for_(i,a,b) for(int i=(a);i<(b);++i)
#define size_of(a) (int)(a).size()
#define allof(a) (a).begin(),(a).end()

typedef long long lint;

int N, M, R, z[1010];

lint cstL[222][222], cstS[222][222];
lint dp[1010][222];

void minUpdate(lint& a, lint b) {
	a = min(a, b);
}

void solve() {	
	for_(k,0,N) for_(i,0,N) for_(j,0,N) {
		minUpdate(cstL[i][j], cstL[i][k] + cstL[k][j]);
		minUpdate(cstS[i][j], cstS[i][k] + cstS[k][j]);
	}
	
	for_(i,0,1010) for_(j,0,222) dp[i][j] = 1LL << 60;
	dp[0][z[0]] = 0;
	
	for_(i,0,R-1) for_(j,0,N) {
		if (dp[i][j] >= 1LL << 60) continue;
		
		lint cc = cstL[z[i]][z[i + 1]];
		if (cc < 1LL << 60) minUpdate(dp[i + 1][j], dp[i][j] + cc);
		
		for_(v,0,N) {
			lint c1 = cstL[z[i]][j];
			lint c2 = cstS[j][v];
			lint c3 = cstL[v][z[i + 1]];
			
			cc = c1 + c2 + c3;
			if (cc < 1LL << 60) minUpdate(dp[i+1][v], dp[i][j] + cc);
		}
	}
	
	lint ans = 1LL << 60;
	for_(i,0,N) minUpdate(ans, dp[R-1][i]);
	cout << ans << endl;
}

int main() {
	while (cin >> N >> M, N) {		
		for_(i,0,N) for_(j,0,N) cstL[i][j] = cstS[i][j] = 1LL << 60;
		for_(i,0,N) cstS[i][i] = cstL[i][i] = 0;
		
		for_(i,0,M) {
			int x, y, t;
			char s;
			cin >> x >> y >> t >> s;
			--x; --y;
			if (s == 'L') cstL[x][y] = cstL[y][x] = t;
			else cstS[x][y] = cstS[y][x] = t;
		}
		
		cin >> R;
		
		for_(i,0,R) {
			cin >> z[i];
			--z[i];
		}
		
		solve();
	}
}