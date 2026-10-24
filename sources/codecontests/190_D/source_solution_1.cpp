#include <bits/stdc++.h>
using namespace std;
const int MAXN = 400005;
int N, K;
map<int, int> mp;
int id = 1;
int a[MAXN];
int tree[MAXN * 4];
inline int left(int x) { return x << 1; }
inline int right(int x) { return (x << 1) + 1; }
int query(int ql, int qr, int l, int r, int at) {
  if (l > qr || r < ql) return -1;
  if (l >= ql && r <= qr) {
    return tree[at];
  }
  int mid = (l + r) / 2;
  int lv = query(ql, qr, l, mid, left(at));
  int rv = query(ql, qr, mid + 1, r, right(at));
  if (lv == -1) return rv;
  if (rv == -1) return lv;
  if (rv >= lv) return rv;
  return lv;
}
void update(int val, int delta, int l, int r, int at) {
  if (l == r) {
    tree[at] += delta;
    return;
  }
  int mid = (l + r) / 2;
  if (val <= mid) {
    update(val, delta, l, mid, left(at));
  } else {
    update(val, delta, mid + 1, r, right(at));
  }
  tree[at] = max(tree[left(at)], tree[right(at)]);
}
int main(int argc, char *argv[]) {
  scanf("%d%d", &N, &K);
  for (int i = 0, _i = N; i < _i; ++i) {
    int x;
    scanf("%d", &x);
    int &ref = mp[x];
    if (ref != 0) {
      a[i] = ref;
    } else {
      ref = id++;
      a[i] = ref;
    }
  }
  int left = 0, right = 0;
  long long ans = 0;
  while (left <= right && right < N) {
    int q = -1;
    while (right < N) {
      update(a[right], 1, 0, N, 1);
      q = query(1, id, 0, N, 1);
      if (q >= K) break;
      right++;
    }
    if (right == N) break;
    ans += (long long)(N - right);
    while (true) {
      update(a[left], -1, 0, N, 1);
      left++;
      q = query(1, id, 0, N, 1);
      if (q >= K) {
        ans += (long long)(N - right);
      } else {
        break;
      }
      if (left == right) {
        break;
      }
    }
    right++;
  }
  cout << ans << "\n";
  return 0;
}
