
//#pragma GCC optimize ("Ofast")
#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstdarg>
#include <cassert>
#include <climits>
#include <cstring>
#include <complex>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <cmath>
#include <ctime>
#include <set>
#include <map>
#include <iomanip>
#include <unordered_map>
#include <bitset>
#include<stack>
#include <type_traits>
// Туц-туц-туц-туц-туц-туц-туц-туц-туц, танцуем ребята
using namespace std;
vector<long long> calc(200004);
long long mod = 1000000007;
int main() {
	std::ios_base::sync_with_stdio(false);
	int t;
	cin >> t;
	for (int i = 0; i <= 8; ++i)
		calc[i] = 2;
	calc[9] = 3;
	for (long long i = 10; i <= 200000; ++i)
		calc[i] = (calc[i - 9] % mod + calc[i - 10] % mod) % mod;
	while (t--) {
		int n, m;
		cin >> n >> m;
		long long t2 = n;
		long long res = 0;
		while (t2 > 0) {
			int t1 = (t2 % 10);
			if (10 - t1 <= m)
				res = (res % mod + calc[m - (10 - t1)] % mod) % mod;
			else
				res = (res % mod + 1) % mod;
			t2 = (t2 / 10);
		}
		cout << res % mod << "\n";
	}
}

	/*
	


aafaeacabbfbebccecffef
1-2
0-1 1

101011
()(())
((()))
11
1001101101
()()((()))
(())()()()
*/


