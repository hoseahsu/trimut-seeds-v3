#include <set>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

typedef long long ll;

#ifdef _MSC_VER
#define __builtin_popcount __popcnt
#endif

int n, m;
int main() {
	while (cin >> n >> m, n) {
		vector<int> a(n);
		for (int i = 0; i < n; i++) cin >> a[i];
		vector<set<ll> > dp(1 << n);
		dp[0] = set<ll>({ 0 });
		for (int i = 1; i < 1 << n; i++) {
			if (__builtin_popcount(i) > m) continue;
			for (int j = 0; j < n; j++) {
				if (i & (1 << j)) {
					for (int k : dp[i - (1 << j)]) {
						dp[i].insert(stoll(to_string(k) + to_string(a[j])));
					}
				}
			}
		}
		set<ll> ret;
		for (int i = 0; i < 1 << n; i++) {
			if (__builtin_popcount(i) == m) {
				ret.insert(dp[i].begin(), dp[i].end());
			}
		}
		cout << ret.size() << endl;
	}
	return 0;
}