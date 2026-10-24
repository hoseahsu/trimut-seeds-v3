#include <iostream>
#include <algorithm>
using namespace std;

static const long MAX = 1000;
static const long VMAX = 10000;

long n, A[MAX], s;
long B[MAX], T[VMAX + 1];

long solve(){
	long ans = 0;
	bool V[MAX];
	for (long i = 0; i < n; i++){
		B[i] = A[i];
		V[i] = false;
	}
	sort(B, B + n);
	for (long i = 0; i < n; i++) T[B[i]] = i;
	for (long i = 0; i < n; i++){
		if (V[i]) continue;
		long cur = i, S = 0, m = VMAX, an = 0;
		while (1){
			V[cur] = true;
			an++;
			long v = A[cur];
			m = min(m, v);
			S += v;
			cur = T[v];
			if (V[cur]) break;
		}
		ans += min(S + (an - 2) * m, m + S + (an + 1) * s);
	}
	return ans;
}

int main(){
	cin >> n;
	s = VMAX;
	for (long i = 0; i < n; i++){
		cin >> A[i];
		s = min(s, A[i]);
	}
	long ans = solve();
	cout << ans << endl;
	return 0;
}