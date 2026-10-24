#include <bits/stdc++.h>
using namespace std;
inline long long read() {
  long long x = 0, f = 1;
  char c = getchar();
  while ((c < '0' || c > '9') && (c != '-')) c = getchar();
  if (c == '-') f = -1, c = getchar();
  while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
  return x * f;
}
string s1;
inline bool check(char x) {
  return x != 'a' && x != 'e' && x != 'i' && x != 'o' && x != 'u';
}
int main() {
  cin >> s1;
  int len = s1.length();
  for (register int i = (0); i < (len); i++) {
    if (check(s1[i]) && check(s1[i + 1]) && s1[i] != 'n') {
      printf("NO\n");
      return 0;
    }
  }
  printf("YES\n");
}
