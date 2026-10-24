#include <bits/stdc++.h>
using namespace std;
inline int read() {
  register int x = 0, f = 1, ch = getchar();
  while (!isdigit(ch)) {
    if (ch == '-') f = -1;
    ch = getchar();
  }
  while (isdigit(ch)) {
    x = x * 10 + ch - '0';
    ch = getchar();
  }
  return x * f;
}
bool prim(long long x) {
  if (x == 1ll || x == 4ll) return false;
  if (x <= 5ll) return true;
  int m = (int)sqrt(x);
  if (x % 6 != 1 && x % 6 != 5) return false;
  for (int i = 5; i <= m; i += 6) {
    if ((x % i == 0) || (x % (i + 2) == 0)) return false;
  }
  return true;
}
bool pr[10000000];
void prime(int n) {
  pr[1] = true;
  for (int i = 2; i <= n; i++) {
    if (!pr[i]) {
      for (int j = 2; j * i <= n; j++) {
        pr[i * j] = true;
      }
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long x;
  cin >> x;
  if (x == 1) {
    cout << 1 << '\n' << 0 << '\n';
  } else if (prim(x)) {
    cout << 1 << '\n';
    cout << 0 << '\n';
  } else {
    prime((int)sqrt(x));
    int res = 0, b = -1, up = -1;
    for (int i = 2; i * 1ll * i <= x; ++i) {
      if (!pr[i] && (x % (i * 1ll) == 0)) {
        res++;
        if (up == -1)
          up = i;
        else if (b == -1)
          b = i;
      }
      if (res >= 3) break;
    }
    if (res < 1) {
      cout << 2 << '\n';
    } else if (res == 1) {
      if (x % (up * up * 1ll) == 0 && (up * up) != x) {
        cout << 1 << '\n';
        cout << up * 1ll * up << '\n';
      } else {
        cout << 2 << '\n';
      }
    } else if (res == 2 && up * 1ll * b == x) {
      cout << 2 << '\n';
    } else {
      cout << 1 << '\n';
      cout << up * 1ll * b << '\n';
    }
  }
  return 0;
}
