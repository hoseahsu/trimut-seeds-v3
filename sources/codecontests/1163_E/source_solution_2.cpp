#include <bits/stdc++.h>
using namespace std;
const int maxn = 200010;
const int maxm = 2000010;
vector<int> ans, vec;
set<int> basis;
set<int>::iterator it;
int ed;
bool v[maxm];
int a[maxn];
void add(int x) {
  int tmp = x;
  if (basis.size()) {
    for (it = --basis.end();; it--) {
      tmp = min(tmp, tmp ^ (*it));
      if (it == basis.begin()) break;
    }
  }
  if (!tmp) return;
  basis.insert(tmp);
  vec.push_back(x);
}
void dfs(int x, int deep = 1) {
  v[x] = 1;
  ans.push_back(x);
  if (deep == (1 << ed)) return;
  for (int i = 0; i < vec.size(); i++) {
    if (!v[x ^ vec[i]]) {
      dfs(x ^ vec[i], deep + 1);
      return;
    }
  }
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  sort(a + 1, a + 1 + n);
  int pos = 1;
  ed = 0;
  for (int i = 1; i < 20; i++) {
    for (; pos <= n && a[pos] < (1 << i); pos++) add(a[pos]);
    if (basis.size() == i) {
      ed = i;
    }
  }
  basis.clear();
  vec.clear();
  for (int i = 1; i <= n && a[i] < (1 << ed); i++) add(a[i]);
  dfs(0);
  printf("%d\n", ed);
  for (int i = 0; i < ans.size(); i++) printf("%d ", ans[i]);
}
