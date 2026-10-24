#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int a[N], t[4 * N][4], sz, n;
set<int> pos[4];
int getCode(char ch) {
  if (ch == 'P') {
    return 1;
  }
  if (ch == 'R') {
    return 2;
  }
  if (ch == 'S') {
    return 3;
  }
  return -1;
}
void update(int idx, int val, int tp) {
  idx += sz - 1;
  t[idx][tp] += val;
  idx >>= 1;
  while (idx >= 1) {
    t[idx][tp] = t[idx << 1][tp] + t[(idx << 1) + 1][tp];
    idx >>= 1;
  }
}
int get(int l, int r, int tp) {
  if (l > r) {
    return 0;
  }
  l += sz - 1;
  r += sz - 1;
  int res = 0;
  while (l <= r) {
    if (l % 2 == 1) {
      res += t[l][tp];
      l++;
    }
    if (r % 2 == 0) {
      res += t[r][tp];
      r--;
    }
    l >>= 1;
    r >>= 1;
  }
  return res;
}
int calcEdge(int l, int r, int tp, int ptp, int ntp) {
  if (l > r) {
    return 0;
  }
  if (pos[ntp].empty()) {
    return 0;
  }
  if (l == 1) {
    r = min(r, *(pos[ntp].rbegin()));
  } else {
    l = max(l, *(pos[ntp].begin()));
  }
  return get(l, r, tp);
}
void printAns() {
  int ans = 0;
  for (int tp = 1; tp <= 3; ++tp) {
    int ptp = tp - 1;
    if (ptp == 0) {
      ptp = 3;
    }
    int ntp = tp + 1;
    if (ntp > 3) {
      ntp = 1;
    }
    int l = 0;
    int r = n + 1;
    if (!pos[ptp].empty()) {
      l = *(pos[ptp].begin());
      r = *(pos[ptp].rbegin());
      ans += calcEdge(1, l - 1, tp, ptp, ntp);
      ans += calcEdge(r + 1, n, tp, ptp, ntp);
      int ll = n + 1;
      int rr = 0;
      if (!pos[ntp].empty()) {
        ll = *pos[ntp].begin();
        rr = *pos[ntp].rbegin();
        l = max(ll, l);
        r = min(rr, r);
        ans += get(l, r, tp);
      }
    } else {
      ans += get(1, n, tp);
    }
  }
  cout << ans << endl;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int q;
  cin >> n >> q;
  sz = 1;
  while (sz < n) {
    sz *= 2;
  }
  for (int i = 1; i <= n; ++i) {
    char ch;
    cin >> ch;
    a[i] = getCode(ch);
    update(i, 1, a[i]);
    pos[a[i]].insert(i);
  }
  printAns();
  for (int i = 1; i <= q; ++i) {
    int idx;
    char ch;
    cin >> idx >> ch;
    int val = getCode(ch);
    update(idx, -1, a[idx]);
    pos[a[idx]].erase(idx);
    a[idx] = val;
    update(idx, 1, a[idx]);
    pos[a[idx]].insert(idx);
    printAns();
  }
  return 0;
}
