#include <bits/stdc++.h>
using namespace std;
long long sqr(long long x) { return (x * x); }
long long dist(pair<long long, long long> a, pair<long long, long long> b) {
  return sqr(a.first - b.first) + sqr(a.second - b.second);
}
long long func(long long i) {
  if (i < 2 || i & 1) return 1;
  return -1;
}
int main() {
  int n;
  scanf("%d", &n);
  vector<pair<long long, pair<long long, long long> > > a;
  long long x, y, r;
  for (int i = 0; i < n; i++) {
    scanf("%lld %lld %lld", &x, &y, &r);
    a.push_back(make_pair(r, make_pair(x, y)));
  }
  long long deg[n];
  memset(deg, 0, sizeof deg);
  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      if (dist(a[i].second, a[j].second) <= sqr(a[j].first) && i != j) deg[i]++;
  double answer = 0.0;
  for (int i = 0; i < n; i++) {
    answer += (double)acos(-1) * a[i].first * a[i].first * func(deg[i]);
  }
  printf("%.20lf\n", answer);
  return 0;
}
