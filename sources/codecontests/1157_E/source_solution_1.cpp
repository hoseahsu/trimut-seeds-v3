#include <bits/stdc++.h>
using namespace std;
const long long MAX_N = 200 * 1000 + 24;
long long n;
long long a[MAX_N], b[MAX_N], c[MAX_N], cnt[MAX_N];
set<long long> s;
int32_t main() {
  cin.tie(0), cout.tie(0), ios::sync_with_stdio(false);
  cin >> n;
  for (long long i = 0; i < n; i++) cin >> a[i];
  for (long long i = 0; i < n; i++) {
    cin >> b[i];
    cnt[b[i]]++;
    if (cnt[b[i]] == 1) s.insert(b[i]);
  }
  set<long long>::iterator it;
  for (long long i = 0; i < n; i++) {
    it = s.lower_bound(n - a[i]);
    if (it == s.end()) it = s.begin();
    c[i] = (a[i] + *it) % n;
    cnt[*it]--;
    if (cnt[*it] == 0) s.erase(it);
  }
  for (long long i = 0; i < n; i++) {
    cout << c[i] << " ";
  }
  cout << endl;
}
