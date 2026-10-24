#include <bits/stdc++.h>
using namespace std;
const int maxn = 10;
void close() { exit(0); }
void init() {
  char s[200];
  scanf("%s", s);
  int n, l;
  l = strlen(s);
  scanf("%d", &n);
  for (int i = 0; i < l; i++)
    if (s[i] < 97) s[i] += 32;
  for (int i = 0; i < l; i++)
    if (s[i] > 96 + n)
      printf("%c", s[i]);
    else if (s[i] > 96)
      printf("%c", s[i] - 32);
    else
      printf("%c", s[i]);
}
int main() {
  init();
  close();
  return 0;
}
