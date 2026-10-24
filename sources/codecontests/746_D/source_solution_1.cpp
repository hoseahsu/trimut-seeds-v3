#include <bits/stdc++.h>
using namespace std;
const int OO = 0x3f3f3f3f, NegOO = -1 * OO, N = 1e4 + 5, mod = 1e9 + 7;
int main() {
  ios_base::sync_with_stdio(0), ios::sync_with_stdio(0), cin.tie(0),
      cout.tie(0);
  int n, k, a, b, cura = 0, curb = 0;
  cin >> n >> k >> a >> b;
  string ans = "";
  for (int c = 0; c < n; c++) {
    if ((a >= b || !b || curb == k) && cura < k && a) {
      ans += "G", cura++, a--, curb = 0;
    } else if (curb < k && b) {
      ans += "B", curb++, b--, cura = 0;
    }
  }
  cout << ((((int)((ans).size())) == n) ? ans : "NO") << "\n";
  return 0;
}
