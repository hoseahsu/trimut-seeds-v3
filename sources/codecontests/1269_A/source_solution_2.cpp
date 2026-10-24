#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
int pre[N], tot;
bool vis[N];
void init() {
  for (int i = 2; i <= N - 5; i++) {
    if (!vis[i]) pre[++tot] = i;
    for (int j = 1; j <= tot; j++) {
      if (i * pre[j] > N - 5) break;
      vis[i * pre[j]] = 1;
      if (i % pre[j] == 0) break;
    }
  }
}
bool judge(int x) {
  for (int i = 2; i * i <= x; i++) {
    if (x % i == 0) return 1;
  }
  return 0;
}
int main() {
  int n;
  scanf("%d", &n);
  for (int i = 4;; i += 2) {
    if (judge(i + n)) {
      printf("%d %d\n", i + n, i);
      return 0;
    }
  }
  return 0;
}
