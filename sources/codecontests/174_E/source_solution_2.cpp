#include <bits/stdc++.h>
using namespace std;
long m[1000001];
bool circle(long a, long b, long c) {
  if (m[a] == -1 || m[b] == -1 || m[c] == -1) return false;
  if (a == b) return true;
  if (m[a] < m[c]) {
    if (m[a] < m[b] && m[b] < m[c])
      return true;
    else
      return false;
  } else {
    if (m[a] > m[b] && m[b] > m[c])
      return false;
    else
      return true;
  }
  return false;
}
int main() {
  long la, lb;
  scanf("%ld %ld", &la, &lb);
  long *a = new long[la];
  long *b = new long[lb];
  for (long i = 0; i < la; i++) scanf("%ld", &a[i]);
  for (long i = 0; i < 1000001; i++) m[i] = -1;
  for (long i = 0; i < lb; i++) {
    scanf("%ld", &b[i]);
    m[b[i]] = i;
  }
  long to = 1;
  long max = 0;
  for (long i = 0; i < la; i++) {
    if (m[a[i]] == -1) continue;
    if (to <= i) to = i + 1;
    while (circle(a[i], a[(to - 1) % la], a[to % la]) && to < i + la) {
      to++;
    }
    if (to - i > max) max = to - i;
  }
  cout << max << endl;
}
