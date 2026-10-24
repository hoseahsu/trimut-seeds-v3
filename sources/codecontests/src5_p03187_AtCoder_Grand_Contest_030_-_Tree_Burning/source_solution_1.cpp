#include <bits/stdc++.h>
typedef long long ll; 
 
using namespace std;

int main() {
	ll L, N;
	cin >> L >> N;
	vector<ll> xr(N + 1);
	vector<ll> xl(N + 1);
	xr[0] = 0;
	xl[0] = 0;
	for (int i = 1; i <= N; ++i) {
		cin >> xr[i];
		xl[N - i + 1] = L - xr[i];
	}

	vector<ll> dr(N + 1, 0);
	vector<ll> dl(N + 1, 0);
	for (int i = 1; i <= N; ++i) {
		dr[i] += dr[i - 1] + xr[i];
		dl[i] += dl[i - 1] + xl[i];
	}

	ll res = 0;
	for (int i = 0; i <= N; ++i) {
		// 最初、右に進む
		int r = (N - i) / 2;
		int l = (N - i + 1) / 2;
		ll tmp_r = (dr[i + r] - dr[i] + dl[l])*2 + xr[i]*2;
		if ((N - i) % 2 == 0) { tmp_r -= xr[i + r]; }
		else { tmp_r -= xl[l]; }

		// 最初、左に進む
		r = (N - i + 1) / 2;
		l = (N - i) / 2;
		ll tmp_l = (dl[i + l] - dl[i] + dr[r])*2 + xl[i]*2;
		if ((N - i) % 2 == 0) { tmp_l -= xl[i + l]; }
		else { tmp_l -= xr[r]; }

		res = max({res, tmp_r, tmp_l});
	}

	cout << res << endl;

	return 0;
}
