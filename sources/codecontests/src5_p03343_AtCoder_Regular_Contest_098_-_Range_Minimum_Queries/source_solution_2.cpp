#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#define N 2005
using namespace std;

int n, k, q, s, e, mn = 1e9, a[N];
vector<int> va, vt;

void f(int p, int q) {
	int i;
	vt.clear();
	if (q - p + 1 < k) return;
	for (i = p; i <= q; i++) vt.push_back(a[i]);
	sort(vt.begin(), vt.end());
	for (i = 0; i <= vt.size() - k; i++) va.push_back(vt[i]);
}

int main()
{
	int i;
	cin >> n >> k >> q;
	for (i = 0; i < n; i++) scanf("%d", &a[i]);
	for (i = 0; i < n; i++) {
		va.clear();
		for (s = 0; s < n; s = e + 1) {
			for (e = s; e <= n && a[e] >= a[i]; e++);
			f(s, e - 1);
		}
		sort(va.begin(), va.end());
		if (va.size() >= q) mn = min(mn, va[q - 1] - va[0]);
	}
    cout << mn << endl;
    return 0;
}