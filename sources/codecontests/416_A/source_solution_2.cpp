#include <bits/stdc++.h>
using namespace std;
char str[4], op[3];
int main() {
  int n;
  while (scanf("%d", &n) != EOF) {
    int mini = -2000000000;
    int maxi = 2000000000;
    for (int val, i = 0; i < n; i++) {
      scanf("%s%d%s", str, &val, op);
      if ((strcmp(str, "<") == 0 && strcmp(op, "Y") == 0) ||
          (strcmp(str, ">=") == 0 && strcmp(op, "N") == 0)) {
        maxi = min(val - 1, maxi);
      } else if ((strcmp(str, "<=") == 0 && strcmp(op, "Y") == 0) ||
                 (strcmp(str, ">") == 0 && strcmp(op, "N") == 0)) {
        maxi = min(val, maxi);
      } else if ((strcmp(str, ">") == 0 && strcmp(op, "Y") == 0) ||
                 (strcmp(str, "<=") == 0 && strcmp(op, "N") == 0)) {
        mini = max(val + 1, mini);
      } else {
        mini = max(val, mini);
      }
    }
    if (mini > maxi)
      puts("Impossible");
    else
      printf("%d\n", mini);
  }
  return 0;
}
