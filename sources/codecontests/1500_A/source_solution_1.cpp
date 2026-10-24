#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 30;
int a[N];

const int M = 3e6 + 10;
vector<pair<int, int>> me[M];
int main() {


	int n;
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		cin >> a[i];
	}

	n = min(n, 1577);
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			int diff = max(a[i], a[j]) - min(a[i], a[j]);
			if (me[diff].size()) {
				int first = me[diff][0].first;
				int second = me[diff][0].second;
				if (i != first && j != second && i != second && j != first) {
					cout << "YES" << endl;
					int ii = i;
					int jj = j;
					if (a[i] < a[j]) swap(ii, jj);
					cout << ii << " " << second << " " << jj << " " << first << endl;
					return 0;
				}
			}
			if (me[diff].size())
				continue;
			if (a[i] > a[j]) {
				me[a[i] - a[j]].push_back({ i,j });
			}
			else {
				me[a[j] - a[i]].push_back({ j,i });
			}
		}
	}
	cout << "NO" << endl;
}