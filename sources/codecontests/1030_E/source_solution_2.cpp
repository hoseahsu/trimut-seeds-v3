#include <bits/stdc++.h>
using namespace std;
const int N = 32;
int main() {
  int n;
  cin >> n;
  vector<int> b(n, 0);
  for (int i = 0; i < n; i++) {
    long long a;
    cin >> a;
    b[i] = __builtin_popcountll(a);
  }
  long long res = 0;
  int sufsum = 0;
  vector<vector<int>> cnt(2, vector<int>(n + 1, 0));
  cnt[0][n] = 1;
  for (int i = n - 1; i >= 0; i--) {
    int sum = 0, mx = 0;
    int add = 0;
    for (int j = i; j < n && j - i < 65; ++j) {
      sum += b[j];
      mx = max(mx, b[j]);
      if (sum % 2 == 0 && mx > sum - mx) add--;
    }
    sufsum += b[i];
    add += cnt[sufsum & 1][i + 1];
    res += add;
    cnt[0][i] = cnt[0][i + 1];
    cnt[1][i] = cnt[1][i + 1];
    cnt[sufsum & 1][i]++;
  }
  cout << res << endl;
  return 0;
}
