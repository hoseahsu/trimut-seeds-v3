#include <bits/stdc++.h>
void gi(long long int &x) {
  char ch = getchar();
  x = 0;
  while (ch < '0' || ch > '9') ch = getchar();
  while (!(ch < '0' || ch > '9')) x = x * 10 + ch - 48, ch = getchar();
}
long long int n, m, l[202020], r[202020], q[202020];
void swap(long long int i, long long int j) {
  long long int t;
  t = l[i];
  l[i] = l[j];
  l[j] = t;
  t = r[i];
  r[i] = r[j];
  r[j] = t;
  t = q[i];
  q[i] = q[j];
  q[j] = t;
}
void qsort(long long int _l, long long int _r) {
  long long int i = _l, j = _r, mid = rand() % (_r - _l + 1) + _l;
  long long int ml = l[mid], mr = r[mid];
  while (i <= j) {
    for (; l[i] < ml || (l[i] == ml && r[i] > mr); i++)
      ;
    for (; l[j] > ml || (l[j] == ml && r[j] < mr); j--)
      ;
    if (i <= j) swap(i++, j--);
  }
  if (_l < j) qsort(_l, j);
  if (i < _r) qsort(i, _r);
}
int lx[202020];
int main() {
  long long int i, j, L = 0, R = 0, s = 0, a, b, c;
  gi(n);
  gi(m);
  for (i = 1; i <= m; i++) {
    gi(a);
    gi(b);
    l[i] = a;
    r[i] = a + b - 1;
    q[i] = i;
  }
  qsort(1, m);
  j = 1;
  for (i = 1; i <= m;) {
    if (l[i] > R + 1) {
      L = l[i];
      R = r[i];
      lx[i] = 1;
      i++;
    } else {
      a = R;
      b = 0;
      for (; j <= m && l[j] <= R + 1; j++)
        if (r[j] > a) a = r[j], b = j;
      if (a > R) R = a;
      s++;
      lx[b] = 1;
      i = j;
    }
  }
  s = 0;
  for (i = 1; i <= m; i++)
    if (lx[i]) s++;
  printf("%d\n", int(m - s));
  for (i = 1; i <= m; i++) l[q[i]] = i;
  for (i = 1; i <= m; i++)
    if (!lx[l[i]]) printf("%d ", (int)i);
  return 0;
}
