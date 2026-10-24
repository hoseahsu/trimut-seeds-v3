#include <bits/stdc++.h>
using namespace std;
struct msp {
  int x, y, t;
} ans;
int n;
int cntans(string& s) {
  int t = 0, f = 0, minm = 0x3f3f3f3f;
  for (int i = 0; i < s.length(); i += 1) {
    if (s[i] == '(')
      ++t;
    else
      --t;
    if (t < minm) minm = t, f = i;
  }
  ++f;
  s = s.substr(f, s.length() - f) + s.substr(0, f);
  return f;
}
int d[301000], f[301000];
void work1() {
  int l = 0, r = 0;
  for (int i = 1; i <= n; i += 1) {
    if (d[i] == 1) {
      l = i;
      break;
    }
  }
  for (int i = n; i >= 1; --i) {
    if (d[i] == -1) {
      r = i;
      break;
    }
  }
  if (l < r) {
    int t = 0;
    for (int i = l; i <= r; i += 1) {
      if (f[i] == 0) ++t;
    }
    if (t > ans.t) ans.x = l, ans.y = r, ans.t = t;
  }
}
void work2() {
  int l = 0x3f3f3f3f, r = 0, t = 0;
  for (int i = 1; i <= n; i += 1) {
    if (f[i] < 1) {
      if (t > ans.t) {
        ans.x = l, ans.y = i, ans.t = t;
      }
      t = 0, l = 0x3f3f3f3f;
    } else {
      if (l == 0x3f3f3f3f) l = i;
      if (f[i] == 1) ++t;
    }
  }
}
int orit;
void work3() {
  int l = 0x3f3f3f3f, r = 0, t = 0;
  for (int i = 1; i <= n; i += 1) {
    if (f[i] < 2) {
      if (t + orit > ans.t) {
        ans.x = l, ans.y = i, ans.t = t + orit;
      }
      t = 0, l = 0x3f3f3f3f;
    } else {
      if (l == 0x3f3f3f3f) l = i;
      if (f[i] == 2) ++t;
    }
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);
  cin >> n;
  string s;
  cin >> s;
  ans.x = ans.y = 0;
  int dta = cntans(s);
  for (int i = 1; i <= n; i += 1) {
    d[i] = (s[i - 1] == '(' ? 1 : -1);
    f[i] = f[i - 1] + d[i];
    if (f[i] == 0) ++ans.t;
  }
  orit = ans.t;
  if (f[n] != 0) {
    cout << 0 << '\n' << 1 << ' ' << 1 << '\n';
    return 0;
  }
  work1();
  work2();
  work3();
  ans.x += dta, ans.y += dta;
  ans.x = (ans.x - 1) % n + 1, ans.y = (ans.y - 1) % n + 1;
  cout << ans.t << '\n' << ans.x << ' ' << ans.y;
  return 0;
}
