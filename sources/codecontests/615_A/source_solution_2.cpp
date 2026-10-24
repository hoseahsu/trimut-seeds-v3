#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, m;
  scanf(" %d %d ", &n, &m);
  vector<int> bulbs(m, 0);
  int b;
  for (int i = 0; i < n; i++) {
    int k;
    scanf(" %d ", &k);
    for (int j = 0; j < k; j++) {
      scanf(" %d ", &b);
      b--;
      bulbs[b] = 1;
    }
  }
  bool possivel = true;
  for (int i = 0; i < bulbs.size(); i++) {
    if (bulbs[i] == 0) possivel = false;
  }
  if (possivel)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
