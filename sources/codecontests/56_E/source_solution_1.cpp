#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int n;
struct Node {
  int h;
  int x;
  int dp;
  int id;
} a[maxn];
bool cmp(Node a, Node b) { return a.x > b.x; }
int sum[maxn];
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d%d", &a[i].x, &a[i].h);
    a[i].id = i;
  }
  sort(a, a + n, cmp);
  for (int i = 0; i < n; i++) a[i].dp = 1;
  sum[a[0].id] = 1;
  for (int i = 0; i < n; i++) {
    int j;
    for (j = i - 1; j >= 0; j -= a[j].dp) {
      if (a[j].x > a[i].x + a[i].h - 1) break;
      a[i].dp += a[j].dp;
    }
    sum[a[i].id] = a[i].dp;
  }
  for (int i = 0; i < n; i++) printf("%d ", sum[i]);
  return 0;
}
