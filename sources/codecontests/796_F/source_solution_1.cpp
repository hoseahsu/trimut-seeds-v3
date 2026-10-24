#include <bits/stdc++.h>
using namespace std;
inline void rd(int& res) {
  res = 0;
  char c;
  bool flag = false;
  while (c = getchar(), c != '-' && (c < '0' || c > '9'))
    ;
  if (c == '-') c = getchar(), flag = true;
  do res = res * 10 + (c ^ 48);
  while (c = getchar(), c >= '0' && c <= '9');
  if (flag) res = -res;
}
const int M = 300000;
int n, m;
int A[M + 5], mark[M + 5], B[M + 5], mx[M + 5], L[M + 5], R[M + 5];
struct Segment_Tree {
  int mx[M * 4 + 5], tag[M * 4 + 5];
  void build(int p, int tl, int tr, int x) {
    mx[p] = x;
    tag[p] = -1;
    if (tl == tr) return;
    int mid = (tl + tr) >> 1;
    build(p << 1, tl, mid, x);
    build(p << 1 | 1, mid + 1, tr, x);
  }
  void up(int p) { mx[p] = max(mx[p << 1], mx[p << 1 | 1]); }
  void down(int p) {
    if (tag[p] != -1) {
      int ls = p << 1, rs = ls | 1;
      if (mx[ls] > tag[p]) {
        tag[ls] = mx[ls] = tag[p];
      }
      if (mx[rs] > tag[p]) {
        tag[rs] = mx[rs] = tag[p];
      }
      tag[p] = -1;
    }
  }
  void update(int l, int r, int x, int p, int tl, int tr) {
    if (mx[p] <= x) return;
    if (l == tl && r == tr) {
      mx[p] = tag[p] = x;
      return;
    }
    down(p);
    int mid = (tl + tr) >> 1;
    if (r <= mid)
      update(l, r, x, p << 1, tl, mid);
    else if (l > mid)
      update(l, r, x, p << 1 | 1, mid + 1, tr);
    else
      update(l, mid, x, p << 1, tl, mid),
          update(mid + 1, r, x, p << 1 | 1, mid + 1, tr);
    up(p);
  }
  int query(int l, int r, int p, int tl, int tr) {
    if (l == tl && r == tr) return mx[p];
    down(p);
    int mid = (tl + tr) >> 1;
    if (r <= mid)
      return query(l, r, p << 1, tl, mid);
    else if (l > mid)
      return query(l, r, p << 1 | 1, mid + 1, tr);
    else
      return max(query(l, mid, p << 1, tl, mid),
                 query(mid + 1, r, p << 1 | 1, mid + 1, tr));
  }
  void modify(int x, int w, int p, int tl, int tr) {
    if (tl == tr) {
      mx[p] = w;
      return;
    }
    down(p);
    int mid = (tl + tr) >> 1;
    if (x <= mid)
      modify(x, w, p << 1, tl, mid);
    else
      modify(x, w, p << 1 | 1, mid + 1, tr);
    up(p);
  }
} sgt1, sgt2;
vector<pair<int, int> > vec[M + 5];
map<int, int> Left;
int main() {
  rd(n);
  rd(m);
  for (int i = 1, i_END_ = n + 1; i < i_END_; ++i) B[i] = -1, mx[i] = 1e9 + 1;
  int tot = 0;
  sgt1.build(1, 1, n, 1e9);
  sgt2.build(1, 1, n, 0);
  for (int i = 1, i_END_ = m + 1; i < i_END_; ++i) {
    int opt, a, b, c;
    rd(opt), rd(a), rd(b);
    if (opt == 1) {
      rd(c);
      mark[i] = c;
      int qry = sgt2.query(a, b, 1, 1, n);
      if (qry > c) {
        puts("NO");
        return 0;
      }
      if (qry == c)
        mark[i] = -1;
      else
        Left[c] = n + 1, vec[a].push_back(pair<int, int>(b, c));
      if (mark[i] == c) tot |= c;
      L[i] = a, R[i] = b;
      sgt1.update(a, b, c, 1, 1, n);
    } else {
      if (mx[a] == 1e9 + 1) mx[a] = sgt1.query(a, a, 1, 1, n);
      sgt2.modify(a, b, 1, 1, n);
      mark[i] = -1;
    }
  }
  for (int i = 1, i_END_ = n + 1; i < i_END_; ++i)
    if (mx[i] == 1e9 + 1)
      mx[i] = sgt1.query(i, i, 1, 1, n);
    else
      sgt1.modify(i, mx[i], 1, 1, n);
  for (int i = 1, i_END_ = m + 1; i < i_END_; ++i) {
    if (mark[i] == -1) continue;
    int qrt = sgt1.query(L[i], R[i], 1, 1, n);
    if (qrt < mark[i]) {
      puts("NO");
      return 0;
    }
  }
  for (int i = 1, i_END_ = n + 1; i < i_END_; ++i) {
    for (int j = 0, j_END_ = vec[i].size(); j < j_END_; ++j) {
      Left[vec[i][j].second] = min(Left[vec[i][j].second], vec[i][j].first);
    }
    if (Left.find(mx[i]) != Left.end() && Left[mx[i]] >= i &&
        Left[mx[i]] != n + 1) {
      Left[mx[i]] = n + 1;
      B[i] = mx[i];
    }
  }
  for (map<int, int>::iterator it = Left.begin(); it != Left.end(); ++it)
    if ((*it).second != n + 1) {
      puts("NO");
      return 0;
    }
  for (int i = 1, i_END_ = n + 1; i < i_END_; ++i) {
    if (B[i] != -1) continue;
    int tmp = 0;
    for (int j = (31) - 1, j_BEGIN_ = 0; j >= j_BEGIN_; --j) {
      if (tmp + (1 << j) <= mx[i] && !(tot & (1 << j))) tmp += 1 << j;
    }
    B[i] = tmp;
    tot |= tmp;
  }
  fprintf(stderr, "tot %d\n", tot);
  puts("YES");
  for (int i = 1, i_END_ = n + 1; i < i_END_; ++i) printf("%d ", B[i]);
  puts("");
  return 0;
}
