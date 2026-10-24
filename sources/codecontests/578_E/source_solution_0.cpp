#include <bits/stdc++.h>
using namespace std;
set<int> L, R, M;
char c[120000];
int d[120000];
int i, n, p, s, t1, t2, t3, t4;
int main() {
  scanf("%s", c + 1);
  n = strlen(c + 1);
  for (int i = n; i > 0; i--)
    if (c[i] == 'L')
      t1++, t3 = i, L.insert(i), M.insert(i);
    else
      t2++, t4 = i, R.insert(i), M.insert(i);
  L.insert(n + 1);
  R.insert(n + 1);
  if (t1 == t2 + 1)
    p = t3;
  else if (t1 + 1 == t2)
    p = t4;
  else
    p = 1;
  for (int i = 1; i <= n; i++) {
    d[i] = p;
    if (c[p] == 'L') {
      L.erase(p);
      M.erase(p);
      p = *R.lower_bound(p);
      if (p == n + 1)
        p = *R.begin();
      else if (c[*M.begin()] == 'R' && *L.lower_bound(p) == n + 1)
        p = *M.begin();
    } else {
      R.erase(p);
      M.erase(p);
      p = *L.lower_bound(p);
      if (p == n + 1)
        p = *L.begin();
      else if (c[*M.begin()] == 'L' && *R.lower_bound(p) == n + 1)
        p = *M.begin();
    }
  }
  for (int i = 1; i < n; i++)
    if (d[i] > d[i + 1]) s++;
  printf("%d\n", s);
  for (int i = 1; i <= n; i++) printf("%d ", d[i]);
}
