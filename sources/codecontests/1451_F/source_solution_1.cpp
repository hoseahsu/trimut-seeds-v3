//Komershan
//@defineintlonglong (telegramm channel)
#include <iostream>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <map>
#include <stack>
#include <set>
using namespace std;

#define int long long

//for coding
#define rd(a) for(auto &i : a) cin >> i;
#define ct(a) for(auto i : a) cout << i << ' ';
#define ctp(a) for(auto i : a) cout << i << '\n';
#define all(a) a.begin(), a.end()

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector <int> xors(n + m - 1, 0);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				int num;
				cin >> num;
				xors[i + j] ^= num;
			}
		}
		bool istrue = true;
		for (int i = 0; i < n + m - 1; i++) {
			istrue = istrue & (xors[i] == 0);
		}
		if (!istrue)
			cout << "Ashish\n";
		else
			cout << "Jeel\n";
	}
}