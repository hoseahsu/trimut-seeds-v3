#include <bits/stdc++.h>

using namespace std;

typedef unsigned int ui;
typedef long long ll;
typedef unsigned long long ull;

constexpr int MAXN = 200000, MAXQ = 200000;

char s[MAXN + 2];
char q[MAXQ + 2][2];
int N, Q;

int sim(int p) {
	if(!(p >= 0 && p < N))
		return p;
	for(int i = 0; i < Q; i++) {
		if(q[i][0] == s[p]) {
			if(q[i][1] == 'L') {
				if(--p < 0)
					return p;
			} else {
				if(++p >= N)
					return p;
			}
		}
	}
	return p;
}

int main() {
	cin >> N >> Q >> s;
	for(int i = 0; i < Q; i++)
		cin >> q[i][0] >> q[i][1];
	int l = -1, r = N - 1;
	do {
		int m = (l + r) / 2;
		if(sim(m) == -1)
			l = m + 1;
		else
			r = m - 1;
	} while(l <= r);
	int ans = l;
	l = 0, r = N;
	do { 
		int m = (l + r) / 2;
		if(sim(m) == N)
			r = m - 1;
		else
			l = m + 1;
	} while(l <= r);
	ans += N - l;
	ans = N - ans;
	cout << ans << endl;
}
