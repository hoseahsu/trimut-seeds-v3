#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  vector<pair<int, int> > v;
  for (int i = 0; i < n; i++) {
    int s, p;
    scanf(" %d %d", &s, &p);
    v.emplace_back(s, -p);
  }
  sort((v).begin(), (v).end());
  int cur = 0;
  int count = 1;
  for (int i = n - 1; i > -1; i--) {
    count = 1;
    while (i > 0 && v[i - 1].first == v[i].first &&
           v[i - 1].second == v[i].second) {
      cur++;
      count++;
      i--;
    }
    cur++;
    if (cur >= k) break;
  }
  printf("%d\n", count);
  return 0;
}
