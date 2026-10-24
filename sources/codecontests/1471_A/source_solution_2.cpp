#include <bits/stdc++.h>

#define int long long

using namespace std;

void solve() {
    int n, x;
    cin >> n >> x;
    int sum = 0, ans = 0;
    for (int i = 0 ;i<n; ++i) {
        int a; cin >> a;
        ans += (a + x - 1) / x;
        sum += a;
    }
    cout << (sum + x - 1) / x << " " << ans << endl;
}

signed main() {
    int t = 1; cin >> t;
    while (t--) {
        solve();
    }
}