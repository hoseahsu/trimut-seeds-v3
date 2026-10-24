#include <bits/stdc++.h>
using namespace std;
const long long MX = 5e5 + 3;
long long T;
int32_t main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> T;
  for (long long w = 0; w < T; w++) {
    long long n, m, cnt = 0;
    cin >> n >> m;
    set<long long> st, edg;
    for (long long i = 0; i < m; i++) {
      long long u, v;
      cin >> u >> v;
      if (cnt < n && st.find(u) == st.end() && st.find(v) == st.end()) {
        edg.insert(i);
        cnt++;
        st.insert(u);
        st.insert(v);
      }
    }
    if (cnt == n) {
      cout << "Matching" << endl;
      for (auto u : edg) cout << u + 1 << " ";
      cout << endl;
    } else {
      cout << "IndSet" << endl;
      cnt = 0;
      for (long long i = 1; i < n * 3 + 1; i++)
        if (cnt < n && st.find(i) == st.end()) cout << i << " ", cnt++;
      cout << endl;
    }
  }
  return 0;
}
