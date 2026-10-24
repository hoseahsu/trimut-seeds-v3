#include <bits/stdc++.h>
const double EPS = 1e-9;
using namespace std;
void dbg() { cout << "\n"; }
template <typename T, typename... A>
void dbg(T a, A... x) {
  cout << a << ' ';
  dbg(x...);
}
int q;
long long k;
long long calc1(long long x) {
  long long ans = 0, base = 1, l = 1, r = 1, tot = 1;
  while (1) {
    if (base * 10ll <= x) {
      l = x - base + 1, r = x - base * 10ll + 2;
      ans += (r + l) * (l - r + 1) * tot / 2ll;
    } else {
      l = x - base + 1, r = 1;
      ans += (r + l) * (l - r + 1) * tot / 2ll;
      break;
    }
    base *= 10ll;
    tot++;
  }
  return ans;
}
long long calc2(long long x) {
  long long ans = 0, base = 1, l = 1, r = 1, tot = 1;
  while (1) {
    if (base * 10ll <= x) {
      l = base, r = base * 10ll - 1;
      ans += (r - l + 1) * tot;
    } else {
      l = base, r = x;
      ans += (r - l + 1) * tot;
      break;
    }
    base *= 10ll;
    tot++;
  }
  return ans;
}
int solve3(long long MAX, long long x) {
  vector<int> v;
  while (MAX) {
    v.push_back(MAX % 10);
    MAX /= 10ll;
  }
  reverse(v.begin(), v.end());
  return v[x - 1];
}
int solve2(long long MAX, long long x) {
  long long l = 1, r = MAX, ans;
  while (l <= r) {
    long long mid = (l + r) >> 1;
    if (calc2(mid) <= x) {
      ans = mid;
      l = mid + 1ll;
    } else
      r = mid - 1ll;
  }
  if (x == calc2(ans)) return ans % 10;
  x -= calc2(ans);
  return solve3(ans + 1, x);
}
int solve1(long long x) {
  long long l = 1, r = 1e9, ans;
  while (l <= r) {
    long long mid = (l + r) >> 1;
    if (calc1(mid) <= x) {
      ans = mid;
      l = mid + 1ll;
    } else
      r = mid - 1ll;
  }
  if (x == calc1(ans)) return ans % 10;
  x -= calc1(ans);
  return solve2(ans + 1, x);
}
int main() {
  scanf("%d", &q);
  while (q--) {
    scanf("%lld", &k);
    printf("%d\n", solve1(k));
  }
  return 0;
}
