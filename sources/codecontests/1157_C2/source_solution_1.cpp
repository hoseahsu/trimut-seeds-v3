#include <bits/stdc++.h>
using namespace std;
const int mx = 2e5 + 10;
int n;
int a[mx];
char ans[mx];
char res[2][mx];
int num;
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &a[i]);
  }
  int l = 1, r = n;
  int minn = -1;
  while (l <= r) {
    if (a[l] < a[r]) {
      if (a[l] > minn) {
        minn = a[l];
        ans[++num] = 'L';
        ++l;
      } else if (a[r] > minn) {
        minn = a[r];
        ans[++num] = 'R';
        --r;
      } else {
        printf("%d\n", num);
        for (int i = 1; i <= num; ++i) {
          printf("%c", ans[i]);
        }
        return 0;
      }
    } else if (a[l] > a[r]) {
      if (a[r] > minn) {
        minn = a[r];
        ans[++num] = 'R';
        --r;
      } else if (a[l] > minn) {
        minn = a[l];
        ans[++num] = 'L';
        ++l;
      } else {
        printf("%d\n", num);
        for (int i = 1; i <= num; ++i) {
          printf("%c", ans[i]);
        }
        return 0;
      }
    } else {
      break;
    }
  }
  if (l == r) {
    if (a[r] > minn) ans[++num] = 'L';
    printf("%d\n", num);
    for (int i = 1; i <= num; ++i) {
      printf("%c", ans[i]);
    }
  } else {
    int tp[2], fg = 0;
    tp[0] = tp[1] = 0;
    if (a[r] > minn) {
      res[0][++tp[0]] = 'L';
      res[1][++tp[1]] = 'R';
      for (int i = l + 1; i < r; ++i) {
        if (a[i] > a[i - 1])
          res[0][++tp[0]] = 'L';
        else
          break;
      }
      for (int i = r - 1; i > l; --i) {
        if (a[i] > a[i + 1])
          res[1][++tp[1]] = 'R';
        else
          break;
      }
      if (tp[0] > tp[1])
        fg = 0;
      else
        fg = 1;
    }
    printf("%d\n", num + tp[fg]);
    for (int i = 1; i <= num; ++i) {
      printf("%c", ans[i]);
    }
    for (int i = 1; i <= tp[fg]; ++i) {
      printf("%c", res[fg][i]);
    }
  }
}
