#include <bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
int n, a[MAXN];
vector<int> dfs(vector<int> &V, int d) {
  if (V.size() == 1 && V[0] == 0) return vector<int>();
  if (d > 20) {
    vector<int> res(21);
    return res;
  }
  bool flag = false;
  for (int i = 0, iend = V.size(); i < iend; ++i) {
    if (V[i] & 1) flag = true;
  }
  vector<int> nxt;
  if (!flag) {
    nxt = V;
    for (int i = 0, iend = nxt.size(); i < iend; ++i) nxt[i] /= 2;
    nxt.erase(unique(nxt.begin(), nxt.end()), nxt.end());
    return dfs(nxt, d + 1);
  } else {
    vector<int> res1, res2;
    {
      nxt = V;
      for (int i = 0, iend = nxt.size(); i < iend; ++i) {
        if (nxt[i] & 1) nxt[i]--;
        nxt[i] /= 2;
      }
      nxt.erase(unique(nxt.begin(), nxt.end()), nxt.end());
      res1 = dfs(nxt, d + 1);
      res1.push_back(1 << d);
    }
    {
      nxt = V;
      for (int i = 0, iend = nxt.size(); i < iend; ++i) {
        if (nxt[i] & 1) nxt[i]++;
        nxt[i] /= 2;
      }
      nxt.erase(unique(nxt.begin(), nxt.end()), nxt.end());
      res2 = dfs(nxt, d + 1);
      res2.push_back(-1 << d);
    }
    if (res1.size() < res2.size())
      return res1;
    else
      return res2;
  }
}
int main() {
  cin >> n;
  for (int i = 1, iend = n; i <= iend; ++i) scanf("%d", &a[i]);
  sort(a + 1, a + 1 + n);
  vector<int> V(a + 1, a + 1 + n);
  vector<int> res = dfs(V, 0);
  cout << res.size() << endl;
  for (int i = 0, iend = res.size(); i < iend; ++i) printf("%d ", res[i]);
  return 0;
}
