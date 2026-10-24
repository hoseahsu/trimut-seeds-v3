#include <bits/stdc++.h>
using namespace std;
int n, ice, pos, a[1005], top;
char ans[1000005];
void divide(int l, int r) {
  int mn = a[l];
  for (int i = (int)(l); i <= (int)(r); i++) mn = min(mn, a[i]);
  for (int i = (int)(l); i <= (int)(r); i++) a[i] -= mn;
  int las = l;
  for (int i = (int)(l); i <= (int)(r); i++)
    if (!a[i]) {
      if (i - 1 >= las) divide(las, i - 1);
      las = i + 1;
    }
  if (r >= las) divide(las, r);
  for (int i = (int)(1); i <= (int)(mn); i++) {
    for (; ice < r;) {
      if (pos == ice)
        ans[++top] = 'A', ice++;
      else
        ans[++top] = 'R', pos++;
    }
    for (; pos + 1 >= l; pos--) ans[++top] = 'L';
    ans[++top] = 'A';
    ice = pos;
  }
}
void work(int l, int r) {
  int L = l - 1;
  for (; a[L]; L--)
    ;
  L++;
  if (2 * (l - L) + 2 >= r - l + 1)
    for (int i = (int)(l); i <= (int)(r); i++) a[i] = 1;
}
int main() {
  scanf("%d", &n);
  int cnt = 0;
  for (int i = (int)(1); i <= (int)(n); i++)
    scanf("%d", &a[i]), cnt += (a[i] != 0);
  int l = 1, r = n;
  for (; !a[l]; l++)
    ;
  for (; !a[r]; r--)
    ;
  int las = l;
  for (int i = (int)(l); i <= (int)(r); i++)
    if (a[i]) {
      if (las <= i - 1) work(las, i - 1);
      las = i + 1;
    }
  if (las <= r) work(las, r);
  pos = -1;
  ice = -1;
  divide(l, r);
  int tp2 = 1;
  for (int i = (int)(2); i <= (int)(top); i++)
    if (ans[i] != 'A' || ans[i - 1] != 'L' || ans[i + 1] != 'L')
      ans[++tp2] = ans[i];
  ans[tp2 + 1] = 0;
  printf("%s", ans + 1);
}
