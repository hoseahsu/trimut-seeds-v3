#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 9;
int n, m, sum[maxn], a;
bool f = false, vis[maxn];
vector<int> v;
int main() {
  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a);
    a %= m;
    int num = v.size();
    for (int j = 0; j < num; j++) {
      int nsum = (v[j] + a) % m;
      if (nsum == 0) {
        f = true;
        goto end;
      }
      if (!vis[nsum]) {
        v.push_back(nsum);
        vis[nsum] = true;
      }
    }
    if (!vis[a]) {
      if (a == 0) {
        f = true;
        goto end;
      }
      v.push_back(a);
      vis[a] = true;
    }
  }
end:
  if (f)
    printf("YES\n");
  else
    printf("NO\n");
  return 0;
}
