#include <bits/stdc++.h>
using namespace std;
template <class K>
inline bool cmax(K& a, const K& b) {
  return (a < b) ? a = b, 1 : 0;
}
template <class K>
inline bool cmin(K& a, const K& b) {
  return (a > b) ? a = b, 1 : 0;
}
inline int read() {
  register int s = 0;
  register char c = getchar();
  while (!isdigit(c)) c = getchar();
  while (isdigit(c)) s = (s << 1) + (s << 3) + c - '0', c = getchar();
  return s;
}
int n, ans;
string s;
map<string, int> p;
int main() {
  register int i;
  n = read();
  for (i = 1; i <= n; i++) cin >> s, ++p[s];
  for (i = 1; i <= n; i++) {
    cin >> s;
    if (!p[s])
      ++ans;
    else
      --p[s];
  }
  printf("%d", ans);
  return 0;
}
