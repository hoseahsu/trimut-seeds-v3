#include <bits/stdc++.h>
using namespace std;
void c_p_c() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int main() {
  int n, k;
  cin >> n >> k;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  vector<int> pref(n + 1, 0);
  for (int i = 0; i < n; i++) {
    pref[i + 1] = pref[i] + v[i];
  }
  double mean = 0.0;
  for (int i = 0; i < n; i++) {
    for (int j = k + i; j <= n; j++) {
      double cc = (double)(pref[j] - pref[i]) / (j - i);
      mean = max(mean, cc);
    }
  }
  cout << setprecision(10);
  cout << mean << "\n";
  return 0;
}
