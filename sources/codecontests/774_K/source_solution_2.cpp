#include <bits/stdc++.h>
using namespace std;
const int INF = 0x3f3f3f3f;
const int maxn = 1e5 + 10;
char a[maxn];
int v[maxn], b[200];
int main() {
  int n;
  b['e'] = b['a'] = b['i'] = b['o'] = b['u'] = b['y'] = 1;
  scanf("%d", &n);
  scanf("%s", a);
  for (int i = 0; i < n; i++) {
    if (b[a[i]] == 0)
      printf("%c", a[i]);
    else if ((a[i] == 'e' && a[i + 1] == 'e' && a[i + 2] != 'e') ||
             (a[i] == 'o' && a[i + 1] == 'o' && a[i + 2] != 'o')) {
      printf("%c%c", a[i], a[i + 1]);
      i++;
    } else {
      printf("%c", a[i]);
      while (a[i] == a[i + 1]) i++;
    }
  }
  printf("\n");
  return 0;
}
