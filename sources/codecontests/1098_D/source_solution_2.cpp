#include <bits/stdc++.h>
using namespace std;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long q;
  cin >> q;
  long long w[60];
  long long mn[60];
  for (long long i = 0; i < 60; i++) mn[i] = -1;
  vector<multiset<long long> > v(60);
  for (long long j = 0; j < 60; j++) w[j] = 0;
  long long b = 0;
  for (long long i = 0; i < q; i++) {
    char kek;
    cin >> kek;
    if (kek == '+')
      b++;
    else
      b--;
    long long num;
    cin >> num;
    long long st = 0, what = 1;
    while (2 * what <= num) {
      what *= 2;
      st++;
    }
    if (kek == '+')
      v[st].insert(num);
    else
      v[st].erase(v[st].find(num));
    if (v[st].size())
      mn[st] = (*v[st].begin());
    else
      mn[st] = -1;
    for (long long j = st + 1; j < 60; j++) {
      if (kek == '+')
        w[j] += num;
      else
        w[j] -= num;
    }
    long long ans = b;
    for (long long j = 0; j < 60; j++)
      if (2 * w[j] < mn[j]) ans--;
    cout << ans << "\n";
  }
  return 0;
}
