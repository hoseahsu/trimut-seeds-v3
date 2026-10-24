#include <bits/stdc++.h>
using namespace std;
int main() {
  char a, b;
  scanf("%c%c", &a, &b);
  int n;
  scanf("%d", &n);
  getchar();
  char s[n][10];
  for (int i = 0; i < n; i++) {
    gets(s[i]);
  }
  bool mark[2];
  memset(mark, 0, sizeof(mark));
  for (int i = 0; i < n; i++) {
    if (s[i][0] == a && s[i][1] == b) {
      printf("Yes\n");
      return 0;
    }
    if (s[i][1] == a) {
      mark[1] = 1;
    }
    if (s[i][0] == b) {
      mark[0] = 1;
    }
    if (mark[1] && mark[0]) {
      printf("Yes\n");
      return 0;
    }
  }
  printf("No\n");
}
