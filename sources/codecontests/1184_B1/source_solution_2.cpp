#include <bits/stdc++.h>
using namespace std;
long long s, b, ans[100005], sum;
struct attack {
  long long a, id;
  bool operator<(const attack& a) const { return this->a < a.a; }
} a[100005];
struct defens {
  long long d, g;
  bool operator<(const defens& a) const { return d < a.d; }
} d[100005];
int main() {
  scanf("%lld%lld", &s, &b);
  for (int i = 1; i <= s; i++) {
    scanf("%lld", &a[i].a);
    a[i].id = i;
  }
  for (int i = 1; i <= b; i++) {
    scanf("%lld%lld", &d[i].d, &d[i].g);
  }
  sort(a + 1, a + s + 1);
  sort(d + 1, d + b + 1);
  for (int i = 1, j = 1; i <= s; i++) {
    while (d[j].d <= a[i].a && j <= b) {
      sum += d[j].g;
      j++;
    }
    ans[a[i].id] = sum;
  }
  for (int i = 1; i <= s; i++) printf("%lld ", ans[i]);
  return 0;
}
