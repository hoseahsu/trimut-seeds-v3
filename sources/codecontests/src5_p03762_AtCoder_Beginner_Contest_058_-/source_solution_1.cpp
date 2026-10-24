#include <bits/stdc++.h>
using namespace std;

typedef long long int lli;

const int MOD = 1e9 + 7;
const int N = 1e5 + 5;
int n, m;
lli x[N];
lli y[N];

int main() {
	cin >> n >> m;

	lli sumX = 0;
	for(int i = 0; i < n; i++) {
		cin >> x[i];
	}
	sort(x, x+n);
	
	for(lli i = 1; i < n; i++) {
		sumX += i*(n-i)*(x[i]-x[i-1]);
		sumX %= MOD;
	}

	lli sumY = 0;
	for(int i = 0; i < m; i++) {
		cin >> y[i];
	}
	sort(y, y+m);
	
	for(lli i = 1; i < m; i++) {
		sumY += i*(m-i)*(y[i]-y[i-1]);
		sumY %= MOD;
	}

	cout << (sumX*sumY)%MOD << endl;

	return 0;
}