#include <bits/stdc++.h>
std::pair<std::pair<int, int>, int> a[262144], pq[262144];
int ans[262144];
std::pair<int, int> bit[262144];
void update(int k, std::pair<int, int> v) {
  ++k;
  while (k) bit[k] = std::max(bit[k], v), k -= k & -k;
}
std::pair<int, int> qry(int k) {
  std::pair<int, int> res(-1, -1);
  ++k;
  while (k < 262144) res = std::max(res, bit[k]), k += k & -k;
  return res;
}
bool cmp(const std::pair<std::pair<int, int>, int> &a,
         const std::pair<std::pair<int, int>, int> &b) {
  return a.first.second > b.first.second;
}
int main() {
  int n, npq = 0;
  memset(bit, -1, sizeof(bit));
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%d%d", &a[i].first.first, &a[i].first.second), --a[i].first.first,
        --a[i].first.second, a[i].second = i;
  std::sort(a, a + n);
  for (int i = 0, j = 0; i < n; ++i) {
    while (j < n && a[j].first.first <= i)
      pq[npq++] = a[j++], std::push_heap(pq, pq + npq, cmp);
    std::pop_heap(pq, pq + npq, cmp), a[i] = pq[--npq];
  }
  for (int i = 0; i < n; ++i) ans[a[i].second] = i;
  bool f = true;
  for (int i = 0; i < n; ++i) {
    std::pair<int, int> r = qry(a[i].first.first);
    if (r.first >= i) {
      std::swap(a[r.second], a[i]);
      f = false;
      break;
    }
    update(i, {a[i].first.second, i});
  }
  puts(f ? "YES" : "NO");
  for (int i = 0; i < n; ++i) printf(" %d" + !i, ans[i] + 1);
  printf("\n");
  if (!f) {
    for (int i = 0; i < n; ++i) ans[a[i].second] = i;
    for (int i = 0; i < n; ++i) printf(" %d" + !i, ans[i] + 1);
    printf("\n");
  }
  return 0;
}
