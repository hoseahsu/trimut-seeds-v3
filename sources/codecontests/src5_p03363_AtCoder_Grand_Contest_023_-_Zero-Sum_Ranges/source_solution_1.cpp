#include <bits/stdc++.h>
using namespace std;


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);

	int n;
	cin >> n;
	map<long long, int> mp;
	mp[0] = 1;
	long long ans = 0;
	long long sum = 0;
	for(int i = 0; i < n; i++) {
		int t;
		cin >> t;
		sum += t;
		ans += mp[sum];
		mp[sum]++;
	}
	cout << ans << endl;
	return 0;
}	
