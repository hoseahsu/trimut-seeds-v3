#include "bits/stdc++.h"
using namespace std;

//#define int long long
#define DEBUG 0
#define rep(i,a,b) for(int i=(a);i<(b);i++)
#define rrep(i,a,b) for(int i=(b)-1;i>=(a);i--)
#define all(a) (a).begin(),(a).end()
#define dump(o) if(DEBUG){cerr<<#o<<" "<<o<<endl;}
#define dumpc(o) if(DEBUG){cerr<<#o; for(auto &e:(o))cerr<<" "<<e;cerr<<endl;}
using ll = long long; using ull = unsigned long long; using pii = pair<int, int>;
static const int INF = 0x3f3f3f3f; static const long long INFL = 0x3f3f3f3f3f3f3f3fLL;
static const int MOD = 1e9 + 7;

#if DEBUG
const int MAX = 10;
#else
const int MAX = 510;
#endif

int D[MAX][MAX] = {};
int H, W;

bool A[MAX][MAX] = {};

signed main() {
	cin >> H >> W;
	rep(i, 0, H)rep(j, 0, W) {
		cin >> D[i][j];
	}
	rep(i, 0, H)rep(j, 0, W) {
		if (D[i][j]) {
			A[i + 1][j + 1] = true;
			int d = D[i][j];
			rep(ii, i, i + 3)rep(jj, j, j + 3) {
				D[ii][jj] -= d;
			}
		}
	}
	rep(i, 0, H)dumpc(A[i]);
	vector<pii> v;
	rep(i, 0, H)rep(j, 0, W) {
		if (!A[i][j])continue;
		int cnt = 0;
		rep(ii, i - 1, i + 2)rep(jj, j - 1, j + 2) {
			if (A[ii][jj])cnt++;
		}
		if (cnt == 2)v.emplace_back(pii(i, j));
		if (cnt == 1) {
			v.emplace_back(pii(i, j));
			v.emplace_back(pii(i, j));
		}
	}
	dump(v.size());
	sort(all(v));
	cout << v[1].first << " " << v[1].second << " " << v[0].first << " " << v[0].second << endl;
	return 0;
}