#include <bits/stdc++.h>
using namespace std;
long long sum[300008], record[300008], a[300008];
struct Tree {
  long long value, id;
} tree[300008];
int cmp(Tree a, Tree b) {
  if (a.value == b.value)
    return a.id < b.id;
  else
    return a.value < b.value;
}
int main() {
  long long n, i, j, ans, l = 0, r = 0, temp, num;
  sum[0] = 0;
  scanf("%I64d", &n);
  for (i = 1; i <= n; i++) {
    scanf("%I64d", &tree[i].value);
    tree[i].id = i;
    sum[i] = sum[i - 1];
    a[i] = tree[i].value;
    if (tree[i].value > 0) sum[i] += tree[i].value;
  }
  sort(tree + 1, tree + n + 1, cmp);
  for (i = 1; i < n; i++)
    if (tree[i].value == tree[i + 1].value) {
      for (j = i + 2; j <= n && tree[j].value == tree[j - 1].value; j++)
        ;
      j--;
      temp = sum[tree[j].id - 1] - sum[tree[i].id] + tree[i].value * 2;
      if ((l == 0 && r == 0) || ans < temp) {
        ans = temp;
        l = tree[i].id;
        r = tree[j].id;
      }
      i = j;
    }
  num = 0;
  for (i = 1; i < l; i++) record[num++] = i;
  for (i = l + 1; i < r; i++)
    if (a[i] < 0) record[num++] = i;
  for (i = r + 1; i <= n; i++) record[num++] = i;
  printf("%I64d %I64d\n", ans, num);
  for (i = 0; i < num; i++) printf("%I64d ", record[i]);
  return 0;
}
