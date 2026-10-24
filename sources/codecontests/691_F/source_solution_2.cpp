#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e16;
const long long MOD = 1000000007;
const int N = 3000000 + 10;
int n, m;
long long a[N], q[N];
long long c[N], s[N];
long long bit[N];
void init() {
  scanf("%d", &n);
  for (int i = (1); i <= (n); i++) {
    scanf("%lld", &a[i]);
    c[a[i]]++;
  }
  for (int i = (1); i <= (N - 1); i++) s[i] = s[i - 1] + c[i];
  for (int i = (1); i <= (N - 1); i++)
    if (c[i]) {
      for (int j = i; j < N; j += i) {
        if (i < j / i) {
          bit[j - i + 1] += (s[N - 1] - s[j / i - 1]) * c[i];
          bit[j + 1] -= (s[N - 1] - s[j / i - 1]) * c[i];
        } else {
          bit[j - i + 1] += (s[N - 1] - s[j / i - 1] - 1) * c[i];
          bit[j + 1] -= (s[N - 1] - s[j / i - 1] - 1) * c[i];
        }
      }
    }
  for (int i = (1); i <= (N - 1); i++) bit[i] += bit[i - 1];
  scanf("%d", &m);
  for (int i = (1); i <= (m); i++) {
    int x;
    scanf("%d", &x);
    printf("%lld\n", bit[x]);
  }
}
int main() { init(); }
