#include <bits/stdc++.h>
using namespace std;
const int MaxN = 100000 + 10, MaxL = 12;
char str[MaxL];
int sl[MaxN], arr[MaxN][MaxL], n;
bool cmp(int x, int y) {
  int t;
  for (int i = y; i <= sl[x]; i++) {
    if (arr[x][i] == -1)
      t = 9;
    else
      t = arr[x][i];
    if (arr[x - 1][i] != t) return arr[x - 1][i] < t;
  }
  return false;
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%s", str + 1);
    sl[i] = strlen(str + 1);
    for (int j = 1; j <= sl[i]; j++)
      if (str[j] != '?')
        arr[i][j] = str[j] - '0';
      else
        arr[i][j] = -1;
  }
  for (int i = 1; i <= n; i++) {
    bool same = (sl[i] == sl[i - 1]);
    if (sl[i - 1] > sl[i]) {
      printf("NO\n");
      return 0;
    }
    for (int j = 1; j <= sl[i]; j++)
      if (same) {
        if (arr[i][j] != -1) {
          if (arr[i][j] < arr[i - 1][j]) {
            printf("NO\n");
            return 0;
          }
          if (arr[i][j] > arr[i - 1][j]) same = false;
        } else {
          if (cmp(i, j + 1))
            arr[i][j] = arr[i - 1][j];
          else {
            if (arr[i - 1][j] != 9)
              arr[i][j] = arr[i - 1][j] + 1;
            else {
              printf("NO\n");
              return 0;
            }
            same = false;
          }
        }
      } else if (arr[i][j] == -1)
        arr[i][j] = (j == 1 ? 1 : 0);
    if (same) {
      printf("NO\n");
      return 0;
    }
  }
  printf("YES\n");
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= sl[i]; j++) printf("%d", arr[i][j]);
    printf("\n");
  }
  return 0;
}
