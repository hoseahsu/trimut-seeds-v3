#include <bits/stdc++.h>

using namespace std;

int main() {
    int t;
    cin >> t;
    for (int tt = 0; tt < t; tt++) {
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort(a.begin(), a.end());
        long long ans = 0;
        for (int i = 1; i < n; i++) {
            int x = upper_bound(a.begin(), a.begin() + i, r - a[i]) - a.begin();
            int y = lower_bound(a.begin(), a.begin() + i, l - a[i]) - a.begin();
            ans += 1LL * (x - y);
        }
        cout << ans << endl;
    }
}
