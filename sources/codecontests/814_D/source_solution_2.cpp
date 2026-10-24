#include <bits/stdc++.h>
using namespace std;
inline long long sqr(long long x) { return (x * x); }
inline long long dist(pair<long long, long long> a,
                      pair<long long, long long> b) {
  return sqr(a.first - b.first) + sqr(a.second - b.second);
}
int main() {
  vector<pair<long long, pair<long long, long long> > > a;
  int d;
  double answer;
  int n;
  scanf("%d", &n);
  long long x, y, r;
  for (int i = 0; i < n; i++) {
    scanf("%lld %lld %lld", &x, &y, &r);
    a.push_back(make_pair(r, make_pair(x, y)));
  }
  sort(a.begin(), a.end());
  for (int i = 0; i < n; i++) {
    d = 0;
    for (int j = i + 1; j < n; j++)
      if (dist(a[i].second, a[j].second) <= sqr(a[j].first)) d++;
    answer += (double)acos(-1) * sqr(a[i].first) * ((!d || d & 1) ? 1 : -1);
  }
  printf("%.10lf\n", answer);
  return 0;
}
