#include <bits/stdc++.h>
using namespace std;
const int maxN = 100000 + 100;
int a[maxN], perm[maxN], first[maxN];
bool used[maxN];
int main() {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> a[i];
  for (int i = 1; i <= n; ++i)
    if (first[a[i]] == 0) first[a[i]] = i;
  for (int i = 1; i <= n; ++i)
    if (first[i] != 0) perm[first[i]] = i;
  int last = 1;
  for (int i = 1; i <= n; ++i)
    if (perm[i] == 0) {
      while (first[last] != 0) ++last;
      first[last] = i;
      perm[i] = last;
    }
  for (int i = 1; i <= n; ++i) cout << perm[i] << " ";
  cout << endl;
  return 0;
}
