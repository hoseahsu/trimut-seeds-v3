#include <bits/stdc++.h>
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
using namespace std;
void file() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
vector<int> v;
int solve(int a, int b, multiset<int>& st) {
  bool ok = 1;
  int ans = 0, last;
  for (auto e : st) {
    if (ok)
      last = e;
    else
      ans += (e - last);
    ok = !ok;
  }
  return ans;
}
int main() {
  file();
  int n;
  cin >> n;
  n *= 2;
  v.resize(n);
  multiset<int> st;
  for (auto& e : v) {
    cin >> e;
    st.insert(e);
  }
  int ans = INT_MAX;
  for (int i = 0; i < n; i++) {
    st.erase(st.find(v[i]));
    for (int k = 0; k < n; k++) {
      if (i == k) continue;
      st.erase(st.find(v[k]));
      ans = min(ans, solve(i, k, st));
      st.insert(v[k]);
    }
    st.insert(v[i]);
  }
  cout << ans << endl;
}
