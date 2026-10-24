#include <bits/stdc++.h>
using namespace std;
const int md = 1010;
int n, ar[md], m;
void oku() {
  scanf(" %d", &n);
  for (int i = 1; i <= n; i++) scanf(" %d", &ar[i]);
  scanf(" %d", &m);
  for (int a, b, i = 1; i <= m; i++) {
    scanf(" %d %d", &a, &b);
    ar[a - 1] += b - 1;
    ar[a + 1] += ar[a] - b;
    ar[a] = 0;
  }
  for (int i = 1; i <= n; i++) printf("%d\n", ar[i]);
}
int main() { oku(); }
