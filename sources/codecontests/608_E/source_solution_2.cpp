#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000010;
char a[maxn], b[maxn];
int f[maxn];
inline void rev(char &x) {
  if (x == 'N')
    x = 'S';
  else if (x == 'S')
    x = 'N';
  else if (x == 'W')
    x = 'E';
  else
    x = 'W';
}
int main() {
  int n;
  scanf("%d", &n);
  scanf("%s%s", a + 1, b + 1);
  reverse(a + 1, a + n);
  rev(a[1]);
  for (int i = 2; i < n; i++) {
    rev(a[i]);
    int j = f[i - 1];
    while (j && a[j + 1] != a[i]) j = f[j];
    if (a[j + 1] == a[i]) f[i] = j + 1;
  }
  int k = 0;
  for (int i = 1; i < n; i++) {
    while (k && a[k + 1] != b[i]) k = f[k];
    if (a[k + 1] == b[i]) k++;
  }
  if (k)
    puts("NO");
  else
    puts("YES");
  return 0;
}
