#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

const ll MOD = 1000000007;

int N, K;
ll dp[110][10010];

int main() {
	cin >> N >> K;
	dp[N][0] = 1;
	for (int i = N-1; i>=0; --i) {
		rep(j, 10010) if (dp[i+1][j] != 0) {
			for (int k = 0; k <= K; ++k) {
				int t = (i+1)-k;

				if (t < 0 || t > j) {
					dp[i][j] = (dp[i][j] + dp[i+1][j]) % MOD;
				} else {
					int num = (j-t)/(i+1) + 1;
					dp[i][j+num] = (dp[i][j+num] + dp[i+1][j]) % MOD;
				}
			}
		}
	}

	ll ret = N * K * (K+1) / 2;
	rep(i, N-1) ret = ret * (K+1) % MOD;

	rep(i, 10010) if (dp[0][i]>0) {
		ret = (ret - dp[0][i] * i % MOD);
		if (ret < 0) ret += MOD;
	}

	cout << ret << endl;

	return 0;
}