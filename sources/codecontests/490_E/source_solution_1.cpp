#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 10;
const int MAXS = 10;
int n;
char s[MAXN][MAXS], ts[MAXS];
int restore[MAXN];
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%s", s[i]);
  }
  bool valid = true;
  int last = 0;
  for (int i = 1; i <= n; ++i) {
    int l = 0, r = 0;
    int num = 0;
    for (int j = 0; s[i][j]; ++j) {
      if (s[i][j] == '?') {
        if (j == 0) {
          l = 1;
          r = 9;
        } else {
          l = l * 10;
          r = r * 10 + 9;
        }
      } else {
        num = num * 10 + s[i][j] - '0';
      }
    }
    if (r == 0) {
      if (num > last) {
        last = num;
        restore[i] = num;
      } else {
        valid = false;
        break;
      }
    } else {
      int next = -1, m = strlen(s[i]);
      while (l <= r) {
        int mid = (l + r) / 2;
        int tmp = mid;
        for (int j = m - 1; j >= 0; --j) {
          if (s[i][j] == '?') {
            ts[j] = tmp % 10;
            tmp /= 10;
          } else {
            ts[j] = s[i][j] - '0';
          }
        }
        int num = 0;
        for (int j = 0; j < m; ++j) {
          num = num * 10 + ts[j];
        }
        if (num > last) {
          r = mid - 1;
          if (next == -1 || next > num) {
            next = num;
          }
        } else {
          l = mid + 1;
        }
      }
      if (next == -1) {
        valid = false;
        break;
      }
      restore[i] = last = next;
    }
  }
  if (valid) {
    puts("YES");
    for (int i = 1; i <= n; ++i) {
      printf("%d\n", restore[i]);
    }
  } else {
    puts("NO");
  }
  return 0;
}
