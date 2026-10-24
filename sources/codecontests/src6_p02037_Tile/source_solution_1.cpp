#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define int long long
using namespace std;
signed main() {
	int h, w, a, b; cin >> h >> w >> a >> b;
	a = h % a; b = w % b;
	cout << a * w + b * h - a * b << endl;
}
