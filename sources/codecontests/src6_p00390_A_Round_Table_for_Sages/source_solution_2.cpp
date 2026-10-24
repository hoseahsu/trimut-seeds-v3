#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

#define int long long

using namespace std;

signed main() {
	int n;
	cin >> n;

	vector<int> left;
	vector<int> right;

	vector<int> lrs;

	for (int i = 0; i < n; i++) {
		int v;
		cin >> v;
		lrs.emplace_back(v);
	}

	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		if (lrs[i] == 1)left.emplace_back(val);
		else right.emplace_back(val);
	}

	sort(left.begin(), left.end());
	sort(right.begin(), right.end());

	if (left.size() == n || right.size() == n) {
		cout << 0 << endl;
	}
	else {
		cout << left[0] + right[0] << endl;
	}
}
