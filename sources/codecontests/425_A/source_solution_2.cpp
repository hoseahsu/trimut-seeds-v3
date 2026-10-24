#include <bits/stdc++.h>
using namespace std;
struct bb {
  int idx;
  int val;
};
int n, k, a[205];
bb b[205];
int sm[205];
int csum, makssum;
bool cmp(bb a, bb b) { return a.val < b.val; }
int main() {
  scanf("%d %d", &n, &k);
  sm[0] = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &a[i]);
    b[i].val = a[i];
    b[i].idx = i;
    sm[i] = sm[i - 1];
    sm[i] += a[i];
  }
  makssum = a[1];
  sort(b + 1, b + n + 1, cmp);
  int swaps;
  for (int l = 1; l <= n; l++)
    for (int r = l; r <= n; r++) {
      csum = sm[r] - sm[l - 1];
      swaps = k;
      int git = 1, dit = n;
      while (swaps) {
        while (git <= n && (b[git].idx < l || b[git].idx > r)) git++;
        if (git == n + 1) break;
        while (dit >= 1 && (b[dit].idx >= l && b[dit].idx <= r)) {
          dit--;
        }
        if (dit == -1) break;
        if (git > dit) break;
        csum -= b[git].val;
        csum += b[dit].val;
        swaps--;
        git++;
        dit--;
      }
      makssum = max(makssum, csum);
    }
  cout << makssum << endl;
  return 0;
}
