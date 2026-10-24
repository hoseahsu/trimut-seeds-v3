#include <bits/stdc++.h>
int main() {
  int mp[10];
  memset(mp, -1, sizeof(mp));
  mp[3] = 3;
  mp[4] = 6;
  mp[6] = 4;
  mp[7] = 7;
  mp[8] = 0;
  mp[0] = 8;
  mp[9] = 5;
  mp[5] = 9;
  std::string a, b;
  std::cin >> a;
  b = a;
  std::reverse(b.begin(), b.end());
  bool flag = true;
  for (int i = 0; i < b.length(); ++i) flag &= a[i] - '0' == mp[b[i] - '0'];
  puts(flag ? "YES" : "NO");
}
