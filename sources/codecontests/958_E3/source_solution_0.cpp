#include <bits/stdc++.h>
using namespace std;
int main() {
  srand(time(NULL));
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, x, y;
  cin >> n;
  vector<tuple<int, int, int> > A(n << 1);
  vector<int> ans(n);
  function<void(int, int)> solve = [&](int l, int r) {
    if (l == r) return;
    auto line = [&](int i, int j) {
      if (get<2>(A[i]) < n)
        ans[get<2>(A[i])] = get<2>(A[j]) - n;
      else if (get<2>(A[j]) < n)
        ans[get<2>(A[j])] = get<2>(A[i]) - n;
      else
        assert(0);
    };
    auto tp = [&](int i) { return get<2>(A[i]) < n ? 1 : -1; };
    if (r - l == 2) {
      line(l, l + 1);
      return;
    }
    swap(*(A.begin() + l), *min_element(A.begin() + l, A.begin() + r));
    sort(A.begin() + l + 1, A.begin() + r,
         [&](tuple<int, int, int> a, tuple<int, int, int> b) {
           int x1, x2, _, y1, y2, stx, sty;
           tie(x1, y1, _) = a, tie(x2, y2, _) = b;
           tie(stx, sty, _) = A[l];
           x1 -= stx, x2 -= stx;
           y1 -= sty, y2 -= sty;
           return 1ll * x1 * y2 - 1ll * x2 * y1 > 0;
         });
    int cur = 0;
    for (int i = l + 1; i < r; ++i) {
      if (tp(i) != tp(l) and cur == 0) {
        line(i, l);
        solve(l + 1, i);
        solve(i + 1, r);
        return;
      }
      cur += tp(i);
    }
  };
  for (int i = 0; i < n; ++i) {
    cin >> x >> y;
    A[i] = {x, y, i};
  }
  for (int i = 0; i < n; ++i) {
    cin >> x >> y;
    A[i + n] = {x, y, i + n};
  }
  solve(0, n << 1);
  for (int i = 0; i < n; ++i) cout << ans[i] + 1 << '\n';
}
