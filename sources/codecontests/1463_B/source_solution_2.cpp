#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n;


void solve() {

	cin >> n;
	ll sum = 0;
	vector<ll> arr(n);
	for (ll i = 0; i < n; i++) {cin >> arr[i]; sum += arr[i];}

	ll temps = 0;
	for (ll i = 0; i < n; i += 2) {
		temps += arr[i] - 1;
	}
	vector<ll> ans(n);

	if (temps < ceil((1.0 * sum) / 2)) {
		for (int i = 0; i < n; i++) {
			if (i % 2)cout << arr[i] << ' ';
			else cout << 1 << ' ';
		}
	} else {
		for (int i = 0; i < n; i++) {
			if (i % 2)cout << 1 << ' ';
			else cout << arr[i] << ' ';
		}
	}

	cout << endl;

}

int main() {
	ios::sync_with_stdio(false);
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input1.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output1.txt", "w", stdout);
#endif

	int t;
	cin >> t;
	while (t--) {
		solve();

	}

}
