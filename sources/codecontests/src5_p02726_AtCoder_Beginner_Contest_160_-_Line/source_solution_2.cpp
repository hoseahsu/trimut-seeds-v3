#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n, x, y; cin >> n >> x >> y;
	--x, --y;
	vector<int> ans(n - 1);
	for (int j = 0; j < n; ++j)
		for (int k = j + 1; k < n; ++k)
			++ans[min(k - j, abs(k - y) + abs(j - x) + 1) - 1];
	for (auto a : ans) cout << a << endl;

	return 0;
}