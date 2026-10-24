#include <bits/stdc++.h>
using namespace std;
int w[505], b[1005], c[505];
bool vis[505];
int ss[505];
int main() {
  int n, m, i, j;
  cin >> n >> m;
  for (i = 1; i <= n; i++) {
    cin >> w[i];
  }
  for (j = 1; j <= m; j++) {
    cin >> b[j];
  }
  int ret = 0, u = 0;
  stack<int> st;
  for (i = 1; i <= m; i++) {
    stack<int> q;
    while (q.size() != 0) q.pop();
    while (st.size() != 0) {
      int x = st.top();
      st.pop();
      if (x == b[i]) {
        break;
      }
      q.push(x);
    }
    while (q.size() != 0) {
      st.push(q.top());
      ret += w[q.top()];
      q.pop();
    }
    st.push(b[i]);
  }
  cout << ret << endl;
}
