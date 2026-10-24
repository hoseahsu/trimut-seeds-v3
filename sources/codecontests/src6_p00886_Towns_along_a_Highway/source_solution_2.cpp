#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
	void solve() {
		while (1) {
			int n;
			cin >> n;
			if (n == 0) return;
			vector<int> d((n * (n - 1)) / 2, 0);
			for (int i = 0; i < (n * (n - 1)) / 2; i++) cin >> d[i];
			vector<int> _cnt(d[0] + 1);
			vector<int> _x(n, -1);
			for (int i = 0; i < (n * (n - 1)) / 2; i++) _cnt[d[i]]++;
			_x[0] = 0;
			_x[n - 1] = d[0];
			_cnt[d[0]]--;
			vector<vector<int> > ans;
			for (int i = 0; i < (1 << (n - 2)); i++) {
				bool ok = true;
				vector<int> x(_x.begin(), _x.end());
				vector<int> cnt(_cnt.begin(), _cnt.end());
				int l = 1, r = n - 2;
				int sh = n - 3;
				for (int j = d[0]; j > 0; j--) {
					while (cnt[j] > 0 && sh >= 0) {
						int id;
						if ((i >> sh) & 1) {
							id = r;
							x[r--] = j;
						} else {
							id = l;
							x[l++] = d[0] - j;
						}
						for (int k = 0; k < n; k++) {
							if (id == k || x[k] == -1) continue;
							if (!cnt[abs(x[id] - x[k])]--) {
								ok = false;
								break;
							}
						}
						sh--;
						if (!ok) break;
					}
					if (!ok) break;
				}
				if (!ok) continue;
				ans.push_back(x);
			}
			sort(ans.begin(), ans.end());
			ans.erase(unique(ans.begin(), ans.end()), ans.end());
			for (int i = 0; i < ans.size(); i++) {
				for (int j = 1; j < n; j++) {
					if (j == 1)
						cout << ans[i][j] - ans[i][j - 1];
					else
						cout << " " << ans[i][j] - ans[i][j - 1];
				}
				cout << "\n";
			}
			cout << "-----\n";
		}
		return;
	};
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	Solution solution;
	solution.solve();
	return 0;
}
