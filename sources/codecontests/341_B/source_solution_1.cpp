#include <bits/stdc++.h>
using namespace std;
template <class T>
bool umin(T& a, T b) {
  if (a > b) {
    a = b;
    return 1;
  }
  return 0;
}
template <class T>
bool umax(T& a, T b) {
  if (a < b) {
    a = b;
    return 1;
  }
  return 0;
}
int arr[100009], s[100009 << 2], dp[100009];
void upd(int p, int v, int nd, int x, int y) {
  if (x == y) {
    s[nd] = v;
    return;
  }
  int mid = (x + y) >> 1;
  if (p <= mid)
    upd(p, v, nd << 1, x, mid);
  else
    upd(p, v, nd << 1 | 1, mid + 1, y);
  s[nd] = max(s[nd << 1], s[nd << 1 | 1]);
}
int tap(int l, int r, int nd, int x, int y) {
  if (l > y or x > r) return 0;
  if (l <= x and y <= r) return s[nd];
  int mid = (x + y) >> 1;
  int i1 = tap(l, r, nd << 1, x, mid);
  int i2 = tap(l, r, nd << 1 | 1, mid + 1, y);
  return max(i1, i2);
}
int main() {
  int a;
  scanf("%d", &a);
  for (int i = 0; i < a; i++) scanf("%d", arr + i);
  for (int i = a - 1; i >= 0; i--) {
    dp[i] = tap(arr[i] + 1, a, 1, 1, a) + 1;
    upd(arr[i], dp[i], 1, 1, a);
  }
  int mx = *max_element(dp, dp + a);
  printf("%d\n", mx);
  return 0;
}
