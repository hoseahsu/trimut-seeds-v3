#include <bits/stdc++.h>
using namespace std;
vector<int> as;
int a[20] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43};
int main() {
  int i, j, n;
  as.push_back(1);
  scanf("%d", &n);
  for (j = 0; as.size() <= n; j++)
    for (i = 0; i < as.size(); i++) {
      if (as[i] * a[j] <= n * n * 2) as.push_back(as[i] * a[j]);
    }
  sort(as.begin(), as.end());
  for (i = as.size() - n; i < as.size(); i++) printf("%d ", as[i]);
  return 0;
}
