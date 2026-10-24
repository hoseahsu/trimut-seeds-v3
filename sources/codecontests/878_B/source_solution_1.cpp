#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 50;
int zhan[N], arr[N], top, cnt[N];
long long n, m, K;
int main() {
  int i, j;
  top = 0;
  scanf("%I64d%I64d%I64d", &n, &K, &m);
  bool flag = 1;
  for (i = 1; i <= n; i++) {
    scanf("%d", &arr[i]);
    if (arr[i] != arr[1]) flag = 0;
  }
  if (flag) {
    printf("%I64d\n", (m * n) % K);
    return 0;
  }
  for (i = 1; i <= n; i++) {
    if (top == 0 || zhan[top] != arr[i])
      zhan[++top] = arr[i], cnt[top] = 1;
    else
      cnt[top]++;
    if (cnt[top] == K) cnt[top] = 0, top--;
  }
  int tot = 0;
  for (i = 1; i <= top; i++) {
    for (j = 1; j <= cnt[i]; j++) arr[++tot] = zhan[i];
  }
  int L = 1, R = tot;
  long long tmp = 0;
  while (L < R && arr[L] == arr[R]) {
    int l = L, r = R;
    int num = 0;
    while (num < K && l && r > l && arr[l] == arr[R]) l++, num++;
    while (num < K && l && r > l && arr[r] == arr[R]) r--, num++;
    if (num == K)
      L = l, R = r, tmp += K;
    else
      break;
  }
  flag = 1;
  for (i = L; i <= R; i++)
    if (arr[i] != arr[L]) flag = 0;
  long long len = (R - L + 1) * m;
  if (flag) {
    if (len % K == 0)
      printf("0\n");
    else
      printf("%I64d\n", len % K + tmp);
  } else
    printf("%I64d\n", len + tmp);
  return 0;
}
