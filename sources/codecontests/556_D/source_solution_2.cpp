#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2e5 + 5;
struct Range {
  long long l_bnd, r_bnd;
  int ind;
  Range(long long l = 0, long long r = 0, int i = 0) {
    l_bnd = l;
    r_bnd = r;
    ind = i;
  }
  bool operator<(const Range &other) const { return l_bnd < other.l_bnd; }
} rngs[MAX_N];
struct Range2 {
  long long r_bnd;
  int ind;
  Range2(long long r = 0, int i = 0) {
    r_bnd = r;
    ind = i;
  }
  bool operator<(const Range2 &other) const { return r_bnd > other.r_bnd; }
};
long long l[MAX_N], r[MAX_N];
int ans[MAX_N];
pair<long long, int> a[MAX_N];
int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%lld %lld", &l[i], &r[i]);
    if (i != 0) {
      rngs[i - 1] = Range(l[i] - r[i - 1], r[i] - l[i - 1], i - 1);
    }
  }
  sort(rngs, rngs + n - 1);
  for (int i = 0; i < m; i++) {
    cin >> a[i].first;
    a[i].second = i;
  }
  sort(a, a + m);
  int next_rng = 0, cnt_answered = 0;
  priority_queue<Range2> pq;
  for (int i = 0; i < m; i++) {
    while (next_rng < n - 1 && rngs[next_rng].l_bnd <= a[i].first) {
      pq.push(Range2(rngs[next_rng].r_bnd, rngs[next_rng].ind));
      next_rng++;
    }
    if (pq.empty()) {
      continue;
    }
    Range2 first_right = pq.top();
    if (first_right.r_bnd < a[i].first) {
      printf("No\n");
      return 0;
    }
    pq.pop();
    ans[first_right.ind] = a[i].second;
    cnt_answered++;
  }
  if (cnt_answered != n - 1) {
    printf("No\n");
    return 0;
  }
  printf("Yes\n");
  for (int i = 0; i < n - 1; i++) {
    printf("%d ", ans[i] + 1);
  }
  printf("\n");
  return 0;
}
