#include <bits/stdc++.h>
using namespace std;
int a[110], n;
vector<int> tmp;
vector<vector<int>> ans;
void work(const vector<int>& v) {
  int now = 1;
  for (const auto& i : v) reverse(a + now, a + now + i), now += i;
  reverse(a + 1, a + n + 1);
}
int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
  for (int i = 1; i <= n - 1; i++) {
    tmp.clear();
    for (int j = 1; j <= i - 1; j++) tmp.push_back(1);
    if (i & 1) {
      for (int j = n - i + 1; j; j--)
        if (a[j] == i) {
          tmp.push_back(n - i + 1 - j + 1);
          if (j != 1) tmp.push_back(j - 1);
        }
      reverse(tmp.begin(), tmp.end());
    } else {
      for (int j = i; j <= n; j++)
        if (a[j] == i) {
          tmp.push_back(j - i + 1);
          if (j != n) tmp.push_back(n - j);
        }
    }
    if (tmp.size() > 1) {
      ans.push_back(tmp);
      work(tmp);
    }
  }
  if (a[1] != 1) {
    tmp.clear();
    for (int i = 1; i <= n; i++) tmp.push_back(1);
    ans.push_back(tmp);
    work(tmp);
  }
  printf("%d\n", (int)ans.size());
  for (const auto& i : ans) {
    printf("%d", (int)i.size());
    for (const auto& j : i) printf(" %d", j);
    printf("\n");
  }
  return 0;
}
