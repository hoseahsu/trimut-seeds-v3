#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES

#include "bits/stdc++.h"
#define REP(i,a,b) for(i=a;i<b;++i)
#define rep(i,n) REP(i,0,n)
#define ll long long
#define ull unsigned ll
typedef long double ld;
#define ALL(a) begin(a),end(a)
#define ifnot(a) if(not a)
#define dump(x)  cerr << #x << " = " << (x) << endl
using namespace std;

// #define int ll
bool test = 0;
int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
#define INF (1 << 28)
ull mod = (int)1e9 + 7;
//.....................
#define MAX (int)1e6 + 5

int n;
int a[500005];
int b[3];
signed main(void) {
	int i, j, k, l;
	cin >> n;
	rep(i, n) {
		cin >> a[i];
		a[i] %= 3;
		b[a[i]]++;
	}
	int cnt = 0;
	if (b[1] == 0 && b[2] == 0) {
		puts("1");
		return 0;
	}
	cnt += b[0];
	b[0] = 0;

	int tmp = min(b[1], b[2]);
	cnt += tmp * 2;
	b[1] -= tmp;
	b[2] -= tmp;
	if (b[1] > b[2]) {
		cnt += min(b[1], 3);
	}
	else if (b[1] < b[2]) {
		cnt += min(b[2], 3);
	}

	cout << cnt << endl;
	return 0;
}