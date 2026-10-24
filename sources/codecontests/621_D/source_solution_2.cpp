#include <bits/stdc++.h>
using namespace std;
inline long double f(long double a, long double b) { return a * pow(2, b); }
int main() {
  ios::sync_with_stdio(0);
  long double x, y, z;
  cin >> x >> y >> z;
  string ans = "x^y^z";
  long double mn = f(log2(x), f(log2(y), log2(z)));
  if (mn < f(log2(x), f(log2(z), log2(y)))) {
    mn = f(log2(x), f(log2(z), log2(y)));
    ans = "x^z^y";
  }
  if (mn < f(f(log2(x), log2(y)), log2(z))) {
    mn = f(f(log2(x), log2(y)), log2(z));
    ans = "(x^y)^z";
  }
  if (mn < f(log2(y), f(log2(x), log2(z)))) {
    mn = f(log2(y), f(log2(x), log2(z)));
    ans = "y^x^z";
  }
  if (mn < f(log2(y), f(log2(z), log2(x)))) {
    mn = f(log2(y), f(log2(z), log2(x)));
    ans = "y^z^x";
  }
  if (mn < f(f(log2(y), log2(x)), log2(z))) {
    mn = f(f(log2(y), log2(x)), log2(z));
    ans = "(y^x)^z";
  }
  if (mn < f(log2(z), f(log2(x), log2(y)))) {
    mn = f(log2(z), f(log2(x), log2(y)));
    ans = "z^x^y";
  }
  if (mn < f(log2(z), f(log2(y), log2(x)))) {
    mn = f(log2(z), f(log2(y), log2(x)));
    ans = "z^y^x";
  }
  if (mn < f(f(log2(z), log2(x)), log2(y))) {
    mn = f(f(log2(z), log2(x)), log2(y));
    ans = "(z^x)^y";
  }
  cout << ans;
}
