#include <bits/stdc++.h>
using namespace std;
template <class T>
inline T gcd(T a, T b) {
  while (b) {
    a %= b;
    swap(a, b);
  }
  return a;
}
template <class T>
inline T lcm(T a, T b) {
  return a / gcd(a, b) * b;
}
inline int nxt() {
  int wow;
  scanf("%d", &wow);
  return wow;
}
inline long long int lxt() {
  long long int wow;
  scanf("%lld", &wow);
  return wow;
}
inline double dxt() {
  double wow;
  scanf("%lf", &wow);
  return wow;
}
int main() {
  int n = nxt(), h = 0, ans = INT_MAX;
  string s;
  cin >> s;
  for (int i = 0; i < n; i++)
    if (s[i] == 'H') h++;
  for (int i = 0; i < n; i++) {
    int cnt = 0;
    for (int j = i; j < i + h; j++)
      if (s[j % n] == 'T') cnt++;
    ans = min(cnt, ans);
  }
  cout << ans << endl;
  return 0;
}
