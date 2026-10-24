#include <bits/stdc++.h>
using namespace std;
const long long MAXN = 2e5 + 10;
long long n, q;
long long a[MAXN];
struct SegmentTreeNode {
  long long minima;
  long long maxima;
  long long count;
  long long lazy;
  long long sum;
} segtree[MAXN << 2];
void combineChildrenResuts(long long id) {
  long long left = id << 1;
  long long right = left + 1;
  segtree[id].minima = min(segtree[left].minima, segtree[right].minima);
  segtree[id].maxima = max(segtree[left].maxima, segtree[right].maxima);
  segtree[id].sum = segtree[left].sum + segtree[right].sum;
}
void buildSegmentTree(long long id, long long seg_low, long long seg_high) {
  segtree[id].count = seg_high - seg_low + 1;
  if (seg_low == seg_high) {
    segtree[id].minima = segtree[id].maxima = segtree[id].sum = a[seg_low];
    segtree[id].lazy = 0;
    return;
  }
  long long seg_mid = seg_low + ((seg_high - seg_low) >> 1);
  buildSegmentTree(id << 1, seg_low, seg_mid);
  buildSegmentTree((id << 1) + 1, seg_mid + 1, seg_high);
  combineChildrenResuts(id);
}
void applyChanges(long long id, long long y) {
  segtree[id].lazy = segtree[id].minima = segtree[id].maxima = y;
  segtree[id].sum = segtree[id].count * y;
}
void pushLaziness(long long id, long long sl, long long sr) {
  if (sl != sr && segtree[id].lazy != 0) {
    long long y = segtree[id].lazy;
    applyChanges(id << 1, y);
    applyChanges((id << 1) + 1, y);
  }
  segtree[id].lazy = 0;
}
void performMaxQuery(long long id, long long sgl, long long sgr, long long ql,
                     long long qr, long long y) {
  if (sgr < ql || sgl > qr || segtree[id].minima >= y) {
    return;
  }
  if (sgl >= ql && sgr <= qr && segtree[id].maxima < y) {
    applyChanges(id, y);
    return;
  }
  pushLaziness(id, sgl, sgr);
  long long sgm = sgl + ((sgr - sgl) >> 1);
  performMaxQuery(id << 1, sgl, sgm, ql, qr, y);
  performMaxQuery((id << 1) + 1, sgm + 1, sgr, ql, qr, y);
  combineChildrenResuts(id);
}
long long moveAndBuyMaxNumberQuery(long long id, long long sl, long long sr,
                                   long long ql, long long qr, long long &y) {
  if (sl > sr || sl > qr || sr < ql) {
    return 0;
  }
  pushLaziness(id, sl, sr);
  long long ans = 0, sm = sl + ((sr - sl) >> 1);
  if (sl == ql && sr == qr) {
    if (y >= segtree[id].sum) {
      y -= segtree[id].sum;
      ans += segtree[id].count;
      return ans;
    }
    if (y < segtree[id].minima) {
      return 0;
    }
    ans += moveAndBuyMaxNumberQuery(id << 1, sl, sm, ql, sm, y);
    ans += moveAndBuyMaxNumberQuery((id << 1) + 1, sm + 1, sr, sm + 1, qr, y);
    return ans;
  }
  if (qr <= sm) {
    ans += moveAndBuyMaxNumberQuery(id << 1, sl, sm, ql, qr, y);
  } else if (ql > sm) {
    ans += moveAndBuyMaxNumberQuery((id << 1) + 1, sm + 1, sr, ql, qr, y);
  } else {
    ans += moveAndBuyMaxNumberQuery(id << 1, sl, sm, ql, sm, y);
    ans += moveAndBuyMaxNumberQuery((id << 1) + 1, sm + 1, sr, sm + 1, qr, y);
  }
  return ans;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  cin >> n >> q;
  for (long long i = 1; i <= n; i++) {
    cin >> a[i];
  }
  buildSegmentTree(1, 1, n);
  while (q--) {
    long long tp, x, y;
    cin >> tp >> x >> y;
    if (tp == 1) {
      performMaxQuery(1, 1, n, 1, x, y);
    } else {
      cout << moveAndBuyMaxNumberQuery(1, 1, n, x, n, y) << '\n';
    }
  }
  return 0;
}
