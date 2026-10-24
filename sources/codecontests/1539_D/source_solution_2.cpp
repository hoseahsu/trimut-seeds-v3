#include<vector>
#include<map>
#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <queue>
using namespace std;

vector<pair<long long, long long>> v;

int main() {
	ios::sync_with_stdio(false);
	int n;
	int i, j;
	long long cnt = 0;
	long long ans = 0;
	//freopen("input.txt", "r", stdin);
	cin >> n;
	for (i = 0; i < n; i++) {
		long long x, y;
		cin >> x >> y;
		v.push_back(make_pair(y, x));
	}
	sort(v.begin(), v.end());
	j = v.size() - 1;
	i = 0;
	while (i < v.size() && i<=j && j>=0) {
		while (i < v.size() && cnt >= v[i].first) {
			cnt += v[i].second;
			ans += v[i].second;
			i++;
		}
		if (i < v.size() && j>=0 && i<=j) {
			if (v[j].second > v[i].first-cnt) {
				long long tmp;
				tmp = v[i].first - cnt;
				v[j].second -=tmp;
				cnt += tmp;
				ans += tmp * 2;
			}
			else {
				cnt += v[j].second;
				ans += v[j].second * 2;
				v[j].second = 0;
				j--;
			}
		}
	}
	cout << ans << endl;
	return 0;
}
