#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
const int maxk = 105;
vector<pair<int, long double> > f, tmp;
long double g[maxn], t[maxn];
long double ans;
int n, k;
int main() {
  scanf("%d%d", &n, &k);
  f.push_back(make_pair(1, 1.0));
  for (int i = 0; i < n; ++i) {
    tmp.clear();
    for (int k = 0; k < (int)f.size(); ++k) {
      int j = f[k].first;
      long double p = f[k].second;
      if (p < 1e-15) continue;
      g[i + 1] += p * (j * 1.0 / (j + 1)) * ((j + 1) / 2.0);
      tmp.push_back(make_pair(j, p * (j * 1.0 / (j + 1))));
      g[i + 1] += p * (1.0 / (j + 1)) * j;
      tmp.push_back(make_pair(j + 1, p * (1.0 / (j + 1))));
    }
    pair<int, long double> last = tmp[0];
    f.clear();
    for (int k = 1; k < (int)tmp.size(); ++k)
      if (tmp[k].first == last.first)
        last.second += tmp[k].second;
      else {
        f.push_back(last);
        last = tmp[k];
      }
    f.push_back(last);
  }
  for (int i = 1; i <= n; ++i) g[i] += g[i - 1];
  if (k > 1) {
    t[0] = log(1);
    for (int i = 1; i <= n; ++i) t[0] = t[0] + log(k - 1) - log(k);
    for (int i = 1; i <= n; ++i)
      t[i] = t[i - 1] + log(n - i + 1) - log(i) - log(k - 1);
    for (int i = 1; i <= n; ++i) t[i] = exp(t[i]);
  } else {
    t[n] = 1;
  }
  for (int i = 0; i <= n; ++i) ans += g[i] * t[i];
  ans *= k;
  printf("%.100lf\n", (double)ans);
  return 0;
}
