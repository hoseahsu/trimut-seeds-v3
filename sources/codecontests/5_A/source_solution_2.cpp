#include <bits/stdc++.h>
int main() {
  int k = 0;
  int total = 0;
  for (;;) {
    char buf[1000];
    if (!gets(buf)) break;
    if (buf[0] == '+')
      k++;
    else if (buf[0] == '-')
      k--;
    else {
      int pos = -1;
      for (int i = 0; i < strlen(buf); i++) {
        if (buf[i] == ':') {
          pos = i;
          break;
        }
      }
      int len = strlen(buf) - pos - 1;
      total += len * k;
    }
  }
  printf("%d\n", total);
  return 0;
}
