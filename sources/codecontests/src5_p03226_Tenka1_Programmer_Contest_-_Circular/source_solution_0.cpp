#include <bits/stdc++.h>
// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <cmath>
#include <iomanip>
#include <time.h>
#define dibs reserve
#define OVER9000 1234567890
#define ALL_THE(CAKE,LIE) for(auto LIE =CAKE.begin(); LIE != CAKE.end(); LIE++)
#define tisic 47
#define soclose 1e-8
#define chocolate win
// so much chocolate
#define patkan 9
#define ff first
#define ss second
#define abs(x) (((x) < 0)?-(x):(x))
#define uint unsigned int
#define dbl long double
#define pi 3.14159265358979323846
using namespace std;
// mylittledoge

using cat = long long;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

int get_min(vector< vector<int> > & RMQ, int l, int r) {
	int ret = OVER9000;
	for(int i = 0; i < 19; i++) if(((r-l)>>i)&1) {
		ret = min(ret, RMQ[i][l]);
		l += 1<<i;
		if(l == r) break;
	}
	return ret;
}

int get_max(vector< vector<int> > & RMQ, int l, int r) {
	int ret = -1;
	for(int i = 0; i < 19; i++) if(((r-l)>>i)&1) {
		ret = max(ret, RMQ[i][l]);
		l += 1<<i;
		if(l == r) break;
	}
	return ret;
}

int main() {
	cin.sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(10);
	int N;
	cin >> N;
	vector<int> A(N), cnt(N, 0);
	for(int i = 0; i < N; i++) {
		cin >> A[i];
		cnt[--A[i]]++;
	}
	int K = cnt[0];
	if(K == 0) {
		cout << "0\n";
		return 0;
	}
	if(cnt[0] == N) {
		cat ans = 1, mod = 998244353;
		for(int i = 0; i < N; i++) ans = ans * (i+1) % mod;
		cout << ans << "\n";
		return 0;
	}
	vector< vector<int> > occ(N);
	for(int i = 0; i < N; i++) occ[A[i]].push_back(i);
	vector<int> first_idx(N);
	first_idx[0] = occ[0][0];
	while(A[(first_idx[0]+N-1)%N] == 0) first_idx[0] = (first_idx[0]+N-1)%N;
	for(int i = 1; i < N; i++) if(cnt[i]) {
		if(cnt[i] == 1) {
			first_idx[i] = occ[i][0];
			continue;
		}
		int x = 0;
		for(int j = 0; j < (int)occ[i].size(); j++) {
			int d = occ[i][(j+1)%occ[i].size()]-occ[i][j];
			while(d < 0) d += N;
			while(d >= N) d -= N;
			if(d >= N-N/2) first_idx[i] = occ[i][(j+1)%occ[i].size()], x++;
		}
		if(x != 1) {
			cout << "0\n";
			return 0;
		}
	}
	for(int i = 0; i < N; i++) if(cnt[i])
		for(int j = 0; j < (int)occ[i].size(); j++) if(occ[i][j] == first_idx[i]) {
			vector<int> occ_nw;
			for(int k = 0; k < (int)occ[i].size(); k++) occ_nw.push_back(occ[i][(j+k)%occ[i].size()]);
			occ[i] = occ_nw;
			break;
		}
	for(int i = 0; i < K; i++) if(occ[0][i] != (first_idx[0]+i)%N) {
		cout << "0\n";
		return 0;
	}
	vector< pair<int, int> > R(N);
	for(int i = 0; i < N; i++) if(cnt[i]) {
		int x = occ[i].back()-K+1;
		while(x < 0) x += N;
		x %= N;
		R[i] = {x, occ[i][0]};
		int d = occ[i].back()-occ[i][0];
		while(d < 0) d += N;
		d %= N;
		if(d >= K) {
			cout << "0\n";
			return 0;
		}
	}
	vector< vector<int> > RMQ_max(19, vector<int>(N));
	RMQ_max[0] = A;
	for(int i = 1; i < 19; i++) for(int j = 0; j < N; j++)
		RMQ_max[i][j] = max(RMQ_max[i-1][j], RMQ_max[i-1][min(N-1, j + (1<<(i-1)))]);
	vector<int> minval(N);
	for(int i = 0; i < N; i++) {
		minval[i] = get_max(RMQ_max, i, min(N, i+K));
		if(i+K > N) minval[i] = max(minval[i], get_max(RMQ_max, 0, i+K-N));
	}
	vector< vector<int> > RMQ_min(19, vector<int>(N));
	RMQ_min[0] = minval;
	for(int i = 1; i < 19; i++) for(int j = 0; j < N; j++)
		RMQ_min[i][j] = min(RMQ_min[i-1][j], RMQ_min[i-1][min(N-1, j + (1<<(i-1)))]);
	for(int i = 0; i < N; i++) if(cnt[i]) {
		int r = (R[i].ss >= R[i].ff) ? R[i].ss : (N-1);
		for(int j = 18; j >= 0; j--) while(R[i].ff+(1<<j) <= r) {
			if(RMQ_min[j][R[i].ff] <= i) break;
			R[i].ff += 1<<j;
		}
		for(int j = 0; j < 3; j++) {
			if(minval[R[i].ff] <= i) break;
			if(R[i].ff == R[i].ss) {
				cout << "0\n";
				return 0;
			}
			R[i].ff = (R[i].ff+1)%N;
		}
		r = (R[i].ss >= R[i].ff) ? R[i].ss : (N-1);
		for(int j = 18; j >= 0; j--) while(R[i].ff+(1<<j) <= r) {
			if(RMQ_min[j][R[i].ff] <= i) break;
			R[i].ff += 1<<j;
		}
		int l = (R[i].ff <= R[i].ss) ? R[i].ff : 0;
		for(int j = 18; j >= 0; j--) while(R[i].ss-(1<<j) >= l) {
			if(RMQ_min[j][R[i].ss-(1<<j)+1] <= i) break;
			R[i].ss -= 1<<j;
		}
		for(int j = 0; j < 3; j++) {
			if(minval[R[i].ss] <= i) break;
			if(R[i].ff == R[i].ss) {
				cout << "0\n";
				return 0;
			}
			R[i].ss = (R[i].ss+N-1)%N;
		}
		l = (R[i].ff <= R[i].ss) ? R[i].ff : 0;
		for(int j = 18; j >= 0; j--) while(R[i].ss-(1<<j) >= l) {
			if(RMQ_min[j][R[i].ss-(1<<j)+1] <= i) break;
			R[i].ss -= 1<<j;
		}
	}
	vector<int> cnt_pos0(N, 0);
	for(int i = 0; i < N; i++) cnt_pos0[minval[i]]++;
	for(int i = 1; i < N; i++) cnt_pos0[i] += cnt_pos0[i-1];
	cat ans = 1, mod = 998244353;
	for(int i = 0; i < N; i++) {
		if(cnt[i] == 0) {
			if(cnt_pos0[i] <= i) {
				cout << "0\n";
				return 0;
			}
			ans = ans * (cnt_pos0[i]-i) % mod;
			continue;
		}
		int d = R[i].ss-R[i].ff;
		while(d < 0) d += N;
		d %= N;
		ans = ans * (d+1) % mod;
	}
	cout << ans << "\n";
	return 0;
}

// look at my code
// my code is amazing
