#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int p[N], l[N], e[N];
int x[N], y[N];
vector<int> qry[N];
stack<int> st;
int f[N];
int ans[N];
int s[N];
int find(int x) {
  if (f[x] != x) f[x] = find(f[x]);
  return f[x];
}
int main() {
  int n, q;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d%d", &p[i], &l[i]);
    e[i] = p[i] + l[i];
    f[i] = i;
  }
  scanf("%d", &q);
  for (int i = 1; i <= q; i++) {
    scanf("%d%d", &x[i], &y[i]);
    qry[x[i]].push_back(i);
  }
  for (int i = n; i >= 1; i--) {
    while (!st.empty() && p[st.top()] <= e[i]) {
      f[st.top()] = i;
      e[i] = max(e[i], e[st.top()]);
      st.pop();
    }
    if (st.empty())
      s[i] = 0;
    else {
      s[i] = s[st.top()] + p[st.top()] - e[i];
    }
    st.push(i);
    for (auto j : qry[i]) {
      ans[j] = s[i] - s[find(y[j])];
    }
  }
  for (int i = 1; i <= q; i++) printf("%d\n", ans[i]);
  return 0;
}
