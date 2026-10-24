#include <bits/stdc++.h>
using namespace std;
long long sz[200005], n;
template <typename T>
inline void read(T& x) {
  x = 0;
  char ch = getchar();
  long long f = 1;
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = (x << 3) + (x << 1) + (ch ^ 48);
    ch = getchar();
  }
  x *= f;
}
inline long long query(long long x) {
  long long res = 0;
  while (x) {
    res += sz[x];
    x -= (x & (-x));
  }
  return res;
}
inline void add(long long x, long long val) {
  while (x <= n) {
    sz[x] += val;
    x += (x & (-x));
  }
}
int main() {
  cin >> n;
  long long ans = 0;
  for (int i = 2; i <= n; i++) {
    long long sum = 0;
    for (int j = 2; i * j <= n; j++) {
      sum += j;
    }
    ans += sum * 4;
  }
  cout << ans << endl;
  return 0;
}
