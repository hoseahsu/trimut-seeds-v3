#include "iostream"
#include "climits"
#include "list"
#include "queue"
#include "stack"
#include "set"
#include "functional"
#include "algorithm"
#include "string"
#include "map"
#include "unordered_map"
#include "unordered_set"
#include "iomanip"
#include "cmath"
#include "random"
#include "bitset"
#include "cstdio"
#include "numeric"
#include "cassert"
#include "ctime"

using namespace std;

constexpr long long int MOD = 1000000007;
//constexpr int MOD = 1000000007;
//constexpr int MOD = 998244353;
//constexpr long long int MOD = 998244353;
constexpr double EPS = 1e-12;

//int N, M, K, T, H, W, L, R;
long long int N, M, K, T, H, W, L, R;

int func(vector<set<pair<int, int>>>xs, vector<set<pair<int, int>>>ys, vector<int>&x, vector<int>&y, vector<char>&c, int st) {
	int cx = x[st], cy = y[st];
	int ret = 1;
	xs[cx].erase(xs[cx].lower_bound({ cy,0 }));
	ys[cy].erase(ys[cy].lower_bound({ cx,0 }));
	char nx = c[st];
	while (ret < N) {
		if (nx == '^') {
			auto it = xs[cx].lower_bound({ cy,0 });
			if (xs[cx].begin() == it)break;
			it = prev(it);
			ret++;
			cy = it->first;
			nx = c[it->second];
		}
		else if (nx == '<') {
			auto it = ys[cy].lower_bound({ cx,0 });
			if (ys[cy].begin() == it)break;
			it = prev(it);
			ret++;
			cx = it->first;
			nx = c[it->second];
		}
		else if (nx == 'v') {
			auto it = xs[cx].lower_bound({ cy,0 });
			if (xs[cx].end() == it)break;
			ret++;
			cy = it->first;
			nx = c[it->second];
		}
		else {
			auto it = ys[cy].lower_bound({ cx,0 });
			if (ys[cy].end() == it)break;
			ret++;
			cx = it->first;
			nx = c[it->second];
		}
		xs[cx].erase(xs[cx].lower_bound({ cy,0 }));
		ys[cy].erase(ys[cy].lower_bound({ cx,0 }));
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> N;
	vector<int>x(N);
	vector<int>y(N);
	vector<char>c(N);
	map<int, int>xp;
	map<int, int>yp;
	for (int i = 0; i < N; i++) {
		cin >> x[i] >> y[i] >> c[i];
		xp[x[i]] = 0;
		yp[y[i]] = 0;
	}
	int cnt = 0;
	for (auto &i : xp) {
		i.second = cnt++;
	}
	cnt = 0;
	for (auto &i : yp) {
		i.second = cnt++;
	}
	vector<set<pair<int, int>>>xx(xp.size());
	vector<set<pair<int, int>>>yy(yp.size());
	for (int i = 0; i < N; i++) {
		x[i] = xp[x[i]];
		y[i] = yp[y[i]];
		xx[x[i]].insert({ y[i],i });
		yy[y[i]].insert({ x[i],i });
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		ans = max(ans, func(xx, yy, x, y, c, i));
	//	cout << i << " " << ans << endl;
	}
	cout << ans << endl;
}
