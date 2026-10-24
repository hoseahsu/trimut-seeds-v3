#include <bits/stdc++.h>
using namespace std;
int n, x, y;
int mon;
vector<int> ans;
int main() {
  scanf("%d %d %d", &n, &x, &y);
  int coux = 0;
  int couy = 0;
  while (coux < x || couy < y) {
    if ((long long)(coux + 1) * y < (long long)(couy + 1) * x) {
      coux++;
      ans.push_back(1);
    } else if ((long long)(coux + 1) * y > (long long)(couy + 1) * x) {
      couy++;
      ans.push_back(2);
    } else {
      coux++;
      couy++;
      ans.push_back(3);
      ans.push_back(3);
    }
  }
  for (int i = 0; i < n; i++) {
    scanf("%d", &mon);
    if (x == y) {
      printf("Both\n");
      continue;
    }
    mon--;
    if (ans[mon % (x + y)] == 1)
      printf("Vanya\n");
    else if (ans[mon % (x + y)] == 2)
      printf("Vova\n");
    else
      printf("Both\n");
  }
  return 0;
}
