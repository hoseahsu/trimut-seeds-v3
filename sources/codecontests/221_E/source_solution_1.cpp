#include <bits/stdc++.h>
using namespace std;
int inf = 1e9;
const int maxn = 1e5 + 20;
int mn[2][maxn * 4 + 10];
void ADD(int s, int e, int v, int l, int r, int val, int det) {
  if (l <= s && e <= r) {
    mn[det][v] = min(mn[det][v], val + ((det)*2 - 1) * (s - l));
    return;
  }
  if (l >= e || s >= r) {
    return;
  }
  int mid = (s + e) / 2;
  ADD(s, mid, 2 * v, l, r, val, det);
  ADD(mid, e, 2 * v + 1, l, r, val, det);
}
int gt(int s, int e, int v, int pos) {
  int ans = min(mn[0][v] - pos + s, mn[1][v] + pos - s);
  while (e - s > 1) {
    int mid = (s + e) / 2;
    if (pos < mid) {
      v *= 2;
      e = mid;
    } else {
      v *= 2;
      v++;
      s = mid;
    }
    ans = min(min(mn[0][v] - pos + s, mn[1][v] + pos - s), ans);
  }
  return ans;
}
int A[maxn];
int B[maxn];
int pos[maxn];
int main() {
  int n;
  cin >> n;
  fill(mn[0], mn[0] + maxn * 4 + 10, inf);
  fill(mn[1], mn[1] + maxn * 4 + 10, inf);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> B[i];
    pos[B[i]] = i;
  }
  cout << endl;
  cout << "\n";
  for (int i = 0; i < n; i++) {
    if (pos[A[i]] >= i) {
      ADD(0, maxn, 1, 0, pos[A[i]] - i + 1, pos[A[i]] - i, 0);
      ADD(0, maxn, 1, pos[A[i]] - i + 1, pos[A[i]] + 1, 1, 1);
      ADD(0, maxn, 1, pos[A[i]] + 1, n, n - i - 1, 0);
    } else {
      ADD(0, maxn, 1, 0, pos[A[i]] + 1, i - pos[A[i]], 1);
      ADD(0, maxn, 1, pos[A[i]] + 1, pos[A[i]] + n - i + 1, n - i - 1, 0);
      ADD(0, maxn, 1, n - i + pos[A[i]] + 1, n, 1, 1);
    }
  }
  for (int i = 0; i < n; i++) {
    int tmp = gt(0, maxn, 1, i);
    cout << tmp << "\n";
  }
  return 0;
}
