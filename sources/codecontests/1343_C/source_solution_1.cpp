#include <bits/stdc++.h>
using namespace std;
int T, n;
long long a[200010];
int main() {
  cin.tie(0);
  ios_base::sync_with_stdio(0);
  cin >> T;
  while (T--) {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    vector<long long> sol;
    sol.push_back(a[0]);
    int fin = 0;
    for (int i = 1; i < n; i++) {
      if (a[i] * sol[fin] > 0) {
        sol[fin] = max(a[i], sol[fin]);
      } else {
        sol.push_back(a[i]);
        fin++;
      }
    }
    long long s = 0;
    for (int i = 0; i < (int)sol.size(); i++) {
      s += sol[i];
    }
    cout << s << "\n";
    sol.clear();
  }
}
