#include <bits/stdc++.h>
using namespace std;
int szh[100000];
int szs[10];
int szz[10];
int numa;
int numq;
int top;
int zhi;
int gabs(int x) {
  if (x > 0)
    return x;
  else
    return -x;
}
void deal(int x) {
  szz[1] = x / 1000;
  szz[2] = x / 100 % 10;
  szz[3] = x / 10 % 10;
  szz[4] = x % 10;
  return;
}
void sp(int x) {
  if (x / 1000 == 0) putchar('0');
  if (x / 100 == 0) putchar('0');
  if (x / 10 == 0) putchar('0');
  printf("%d", x);
  return;
}
void dfs(int x, int w, bool o) {
  int l1;
  int l2;
  if ((w == 4) && (top == 1))
    if ((numa < numq) && (szs[1] < 100000) && (szs[1] > 0) &&
        (gabs(zhi - szs[1]) < 10000) && (szh[gabs(zhi - szs[1])] != x)) {
      numa++;
      szh[gabs(zhi - szs[1])] = x;
      if ((gabs(zhi - szs[1]) == 9894) && (x == 465)) {
        x++;
        x--;
      }
      sp(gabs(zhi - szs[1]));
      sp(x);
      putchar('\n');
      return;
    }
  if (w < 4) {
    if (o) {
      szs[top] = szs[top] * 10 + szz[w + 1];
      dfs(x, w + 1, true);
      szs[top] /= 10;
    }
    top++;
    szs[top] = szz[w + 1];
    dfs(x, w + 1, true);
    top--;
  }
  if (top > 1) {
    l1 = szs[top];
    l2 = szs[top - 1];
    top--;
    szs[top] = l2 + l1;
    dfs(x, w, false);
    szs[top] = l2 - l1;
    dfs(x, w, false);
    szs[top] = l2 * l1;
    dfs(x, w, false);
    top++;
    szs[top] = l1;
    szs[top - 1] = l2;
  }
  return;
}
int main() {
  int f1;
  scanf("%d%d", &zhi, &numq);
  for (f1 = 0; f1 <= 9999; f1++) {
    deal(f1);
    dfs(f1, 0, false);
  }
  return 0;
}
